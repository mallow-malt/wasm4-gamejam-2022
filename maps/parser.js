const Mustache = require('mustache')
const fs = require('fs')

const parseTile = (tile, sprites, xOffset, yOffset) => {
    let rotation
    switch (tile.f) {
        case 1: rotation = "BLIT_2BPP | BLIT_FLIP_X"
            break
        case 2: rotation = "BLIT_2BPP | BLIT_FLIP_Y"
            break
        case 3: rotation = "BLIT_2BPP | BLIT_FLIP_Y | BLIT_FLIP_X"
            break
        default: rotation = "BLIT_2BPP"
            break
    }
    return ({
        sprite: sprites[tile.t],
        x: tile.px[0] - xOffset,
        y: tile.px[1] - yOffset,
        rotation
    })
}

fs.readFile('./maps.ldtk', 'utf8', (_, rawData) => {
    const mapData = JSON.parse(rawData)
    mapData.levels.forEach(level => {
        let [xOffset, yOffset] = level.layerInstances.find(layer => layer.__identifier == "Camera").gridTiles[0].px
        let playerPos = level.layerInstances.find(layer => layer.__identifier == "Player").gridTiles[0].px
        let decals = level.layerInstances.find(layer => layer.__identifier == "Decals").gridTiles.map(tile => {
            return parseTile(tile, ["FullBlockColorA", "HalfBlockColorA"], xOffset, yOffset)
        })
        let tiles = level.layerInstances.find(layer => layer.__identifier == "Tiles").gridTiles.map(tile => {
            return parseTile(tile, ["FullBlockColorA", "HalfBlockColorA"], xOffset, yOffset)
        })
        let data = {
            name: level.identifier,
            decals,
            decalSize: decals.length,
            tiles,
            tileSize: tiles.length,
            playerX: playerPos[0] - xOffset,
            playerY: playerPos[1] - yOffset,
            minX: -xOffset,
            maxX: level.pxWid - xOffset - 160,
            minY: -yOffset,
            maxY: level.pxHei - yOffset - 160
        }
        fs.readFile('./template.mustache', 'utf8', (_, template) => {
            fs.writeFile(`${data.name}.h`, Mustache.render(template, data), _ => {
                console.log('done')
            })
        })
    })
})


