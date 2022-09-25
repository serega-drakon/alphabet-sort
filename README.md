# Alphabet sort
### Данная программа выполняет сортировку всех строк текста в алфавитном порядке.

Вроде как оно все готово, теперь все держится на динамическом массиве!

_Поддержку буквы Ё я так и не добавил, сделать это очевидно, но дрочно. Ну в поэме почему-то её вообще нету)_

## Структура проекта

Проект состоит из двух версий программы : __Debug__ и __Release__. Вторая отличается от первой отсутствием проверок на ошибки и она рекомендуется к использованию, в силу более быстрого исполнения. В каждой соответствующей папке лежит:

- __main.c__ - содержит алгоритм загрузки и обработки файла.
- папка __include__ - содержит все дополнительные функции и обьявления.
- __intArray2d__ - занимается выделением памяти под массив и определением базовых операций над ним.
- __fileio__ - определяет базовые операции по файловому вводу/выводу.
- __funcs2d__ - содержит операции над массивом, основанные на базовых.
- __alphabet__ - содержит всякие функции для сравнения по алфавиту букв и строк. 
- Файлы ввода/вывода __main_in.txt__ и __main_out.txt__ в кодировке "Windows 1251 Cyrillic".

## Как это использовать? 

Необходимо в файл __main_in.txt__ поместить текст, который нужно отсортировать, при этом закодировав его в кодировке, которую поддерживает библиотека Си - _stdio.h_, гарантированно сработает кодировка "Windows 1251", поэтому используйте её. __Запускайте программу__, по итогу работы она сохранит отсортированную версию в __main_out.txt__. Готово!

## Инструкция по сборке

Собрать можно почти в любом компиляторе Си под вашу систему, думаю описывать это не нужно. Внешняя консоль не понадобится в силу того, что ввод/вывод программы совершается через файлы.


