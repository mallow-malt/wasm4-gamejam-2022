// Made because the w4 watch command wasn't working for me on windows ¯\_(ツ)_/¯
const chokidar = require('chokidar')
const spawn = require('cross-spawn')

let child = null;

chokidar.watch('src').on('change', (event, path) => {
    console.log("File changed, rebuilding...")
    const result = spawn.sync('npm', ['--silent', 'run', 'build'], { stdio: 'inherit' })
    if(result.status == 0) {
        console.log("Build successful. Deploying...")
        if (child != null)
            child.kill()
        child = spawn('w4', ['run', '-n', '--no-qr', 'build/cart.wasm'], { stdio: 'inherit' })
    } else {
        console.error("Build failed!")
    }
});
