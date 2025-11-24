# SQLite 

## C/C++

1. Download the [C source code as an amalgamation](https://sqlite.org/download.html)
2. Add the sqlite3.c and sqlite3.h files to ./libs

3. [C++ SQLite project with a Makefile example](https://github.com/t20e/Http_Server_cpp/blob/main/Makefile)

Example C++ code:

```c++
sqlite3 *database;
char *zErrMsg = 0;

int db = sqlite3_open("test.db", &database);
if (db) {
    std::cerr << std::format("Can't open database: {}", sqlite3_errmsg(database));
    return 1;
} else {
    std::cout << "Opened Database\n";
}

const char *createTable = "CREATE TABLE IF NOT EXISTS USERS('UserID' INT PRIMARY KEY NOT NULL, username VARCHAR(32) UNIQUE NOT NULL, passwordHash VARCHAR(255) NOT NULL)";

db = sqlite3_exec(database, createTable, 0, 0, &zErrMsg);
```
