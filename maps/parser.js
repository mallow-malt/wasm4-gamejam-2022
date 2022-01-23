const Mustache = require('mustache')
const fs = require('fs')

const getTileSymbol = (t, f) => {
    switch (t) {
        case 0: return '#'
        case 1: if (f == 2) return 'v' 
            return '^'
        case 3: if (f == 1) return '<' 
            return '>'
        case 4: return 'G'
        case 5: return 'W'
        default:
            break;
    }
}

fs.readFile('./maps.ldtk', 'utf8', (_, rawData) => {
    const mapData = JSON.parse(rawData)
    const parsedData = mapData.levels.map(level => {
        let cameraPos = level.layerInstances.find(layer => layer.__identifier == "Camera").gridTiles[0].px
        let playerPos = level.layerInstances.find(layer => layer.__identifier == "Player").gridTiles[0].px
        let tilesLayer = level.layerInstances.find(layer => layer.__identifier == "Tiles")
        let map = ".".repeat(tilesLayer.__cWid * tilesLayer.__cHei).split('')
        tilesLayer.gridTiles.forEach(tile => {
            let [tileX, tileY] = tile.px
            tileX /= 16
            tileY /= 16
            map[tileY * tilesLayer.__cWid + tileX] = getTileSymbol(tile.t, tile.f)
        })
        return {
            name: level.identifier,
            camX: cameraPos[0],
            camY: cameraPos[1],
            playerX: playerPos[0] / tilesLayer.__gridSize,
            playerY: playerPos[1] / tilesLayer.__gridSize,
            maxCamX: level.pxWid - 160,
            maxCamY: level.pxHei - 160,
            width: tilesLayer.__cWid,
            height: tilesLayer.__cHei,
            tileSize: tilesLayer.__gridSize,
            map: map.join('').match(new RegExp(`.{1,${tilesLayer.__cWid}}`, "g"))
        }
    })

    fs.readFile('./template.mustache', 'utf8', (_, template) => {
        fs.writeFile(`levels.h`, Mustache.render(template, { levels: parsedData }), _ => {
            console.log('done')
        })
    })
})


