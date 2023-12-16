mcs51:  STC89C52RC
pcb:    YL-39

Host Environment:

- install `sdcc`;
- install `stcgal`;

Editor Environment:

- VSCode with `C/C++ Extension Pack`;


## Usage

Press `ctrl + shift + b` to build the current file to `build/` directory.

Then use the following command:

```sh
sudo stcgal build/$fileBaseNoExtension.ihx
```

re-plugin the power of board.