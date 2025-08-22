# So_long

A simple 2D top-down game where the player collects items and escapes through the exit. Built with C and MiniLibX.

## 🎮 About

Collect all items (`C`) and reach the exit (`E`) to win. Navigate using WASD keys while avoiding walls.

## 🚀 Installation

```bash
git clone https://github.com/rekoune/So_long.git
cd So_long
make
./so_long maps/map.ber
```

## 🗺️ Map Format (.ber files)

```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

- `1`: Wall
- `0`: Empty space
- `P`: Player (exactly one)
- `C`: Collectible (at least one)
- `E`: Exit (exactly one)

## 🎮 Controls

| Key | Action |
|-----|--------|
| `W/↑` | Move up |
| `A/←` | Move left |
| `S/↓` | Move down |
| `D/→` | Move right |
| `ESC` | Exit game |


## ✅ Requirements

- Map must be rectangular and surrounded by walls
- Exactly one player and one exit
- At least one collectible
- Valid path to all collectibles and exit

## 👥 Author

[abdellah rekoune](https://github.com/rekoune)
