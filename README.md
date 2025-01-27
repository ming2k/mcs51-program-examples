## 51 MCU DEMO

## Prerequiste

### Prepare Hardware

mcs51:  STC89C52RC
pcb:    YL-39

### Prepare Software

Host Environment:

- install `sdcc`;
- install `stcgal`;

Editor Environment:

- VSCode with `C/C++ Extension Pack`;

## Usage

1. Press `ctrl + shift + b` to build the current file to `build/` directory.

2. Use the following command to burn:

    ```sh
    sudo stcgal build/$fileBaseNoExtension.ihx
    ```

3. re-plugin the power of board.