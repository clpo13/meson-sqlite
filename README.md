# meson-sqlite

Simple SQLite app built with Meson, adapted from the public domain example found at
<https://sqlite.org/quickstart.html>.

## Requirements

- C compiler
- Meson
- Ninja

If the SQLite3 library is present on the system, the app will use that. Otherwise,
an older version will be downloaded from Meson's WrapDB.

## Building

```bash
meson builddir
ninja -C builddir
ninja -C builddir test
```

## Usage

`sqlite-test DATABASE SQL-STATEMENT`

Example:

`sqlite-test test.db "create table tbl1(one varchar(10), two smallint)"`

## License

Public domain per [The Unlicense](LICENSE).
