#include <iostream>
#include <sqlite3.h>

static int callback(void *, int argc, char **argv, char **azColName) {
    int i;
    for(i = 0; i < argc; i++) {
        std::cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << std::endl;
    }
    std::cout << std::endl;
    return 0;
}

int main(int argc, char **argv) {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;

    if(argc != 3) {
        std::cerr << "Usage: " << argv[0] << " DATABASE SQL-STATEMENT" << std::endl;
        return 1;
    }

    rc = sqlite3_open(argv[1], &db);
    if(rc) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 1;
    }

    rc = sqlite3_exec(db, argv[2], callback, 0, &zErrMsg);
    if(rc != SQLITE_OK) {
        std::cerr << "SQL error: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
    }

    sqlite3_close(db);
    return 0;
}
