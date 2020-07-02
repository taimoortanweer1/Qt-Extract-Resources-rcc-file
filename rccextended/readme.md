
RccExtended - компилятор и **декомпилятор** бинарных Qt ресурсов (файлов с расширением .rcc).

Утилита позволяет редактировать ресурсы Qt программ, не имея их исходников.

Алгоритм редактирования:
  
  - распаковка/декомпиляция бинарных Qt ресурсов (при помощи данной утилиты)
  - редактирование распакованных файлов (.png, .xml и т.д.) сторонними средствами
  - компиляция отредактированных файлов обратно в бинарные Qt ресурсы (при помощи данной утилиты)

Эта утилита основана на стандартном компиляторе Qt ресурсов, в который добавлена функция 
декомпиляции ресурсов (ключ коммандной строки `--reverse`).

Чтобы распаковать ресурсы, нужно сделать 2 вещи:

  - перейти в папку с ресурсами
  - запустить утилиту с ключом `--reverse`
  
После запуска, утилита выполняет следующие действия:
  
  - сканирует рабочую директорию в поиске .rcc файлов
  - распаковывает все найденные файлы ресурсов (каждый в отдельную папку)
  - генерирует файлы проекта .qrc и make.bat для обратной компиляции ресурсов в бинарный вид
  - выводит в консоль и записывает в лог информацию о ходе распаковки 

Пример использования:

    cd \Path\To\MyQtResources\
    rcc --reverse