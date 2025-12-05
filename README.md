# pgen

Simple password generator written in C with no dependencies.

- Generates a password of a specified length between 8 - 99.
- Will always contain at least one uppercase and lowercase letter.
- Optionally, will contain at least one number (default true).
- Optionally, will contain at least one symbol (default false).


## Usage

```bash
// Compile the program
make

// Run the executable
./build/pgen
```

## TODO

- [X] Add optional numbers and symbols to password generation. Numbers default on and symbols default off.
- [X] Ensure that if a password uses numbers and symbols, it includes at least one.
- [X] Add ability to regenerate password.
- [ ] Support args to generate a password without needing to interact with the program.

## License

MIT
