import * as w4 from './wasm4'

w4.trace('Hello world!')

store<u32>(w4.PALETTE, 0, 0 * sizeof<u32>())
store<u32>(w4.PALETTE, 0x32cd32, 1 * sizeof<u32>())
store<u32>(w4.PALETTE, 0x8b0000, 2 * sizeof<u32>())
store<u32>(w4.PALETTE, 0xadd8e6, 3 * sizeof<u32>())

export function update (): void {
    store<u16>(w4.DRAW_COLORS, 0x2)
    w4.text("Hello world!", 10, 10)
}
