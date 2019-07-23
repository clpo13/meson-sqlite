# meson-sqlite

Simple SQLite app built with Meson, adapted from the public domain example found at
<https://sqlite.org/quickstart.html>.

## Requirements

- C compiler
- Meson
- Ninja

## Building

```bash
meson builddir
ninja -C builddir
ninja -C builddir test
```

## License

Public domain per [The Unlicense](LICENSE).
