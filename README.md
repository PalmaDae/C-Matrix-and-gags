# Matrix Calculator

Программа позволяет выполнять примитивные функции(сложение и умножение)

## Использование

Клонируйте проект
``` bash
git clone https://github.com/PalmaDae/C-Matrix-and-gags
```

Запустите проект через VSCode или в ручную через

``` bash
./main
```

## Пример работы

``` bash
1 — сложение матриц
2 — умножение матриц
Выберите операцию: 1

Матрица A:
Введите строки и столбцы: 2
2
Матрица B:
Введите строки и столбцы: 2 2

Ввод A:
Введите элемент [0][0]: 1
Введите элемент [0][1]: 2
Введите элемент [1][0]: 3
Введите элемент [1][1]: 4

Ввод B:
Введите элемент [0][0]: 5
Введите элемент [0][1]: 6
Введите элемент [1][0]: 7
Введите элемент [1][1]: 8

Результат:
+--------+--------+
|   6.00 |   8.00 |
+--------+--------+
|  10.00 |  12.00 |
```


## Конфигурация для VSCode

```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "build C project",
            "type": "shell",
            "command": "gcc",
            "args": [
                "-g",
                "main.c",
                "-I", "headers",
                "matrix.c",
                "-o",
                "main"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "problemMatcher": ["$gcc"]
        }
    ],
    "configurations": [
    {
            "name": "Debug C Program (GCC)",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/main",
            "args": ["gcc main.c matrix.c -I headers -o main"],
            "cwd": "${workspaceFolder}"
        }
    ]
}
```
## Чистил память:
PalmaDae

