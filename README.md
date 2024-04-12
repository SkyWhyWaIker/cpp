# cpp
В этом репозитории будут лежать мои коды лабораторных работ по предмету "Основы программирования на С++"

## Task1
### Текст задания 
Передача значения по ссылке.
1. Объявите (в отельном заголовочном файле) и реализуйте (в другом файле) процедуры (они не возвращают значений!) согласно варианту.
2. Все процедуры должны быть написаны в двух вариантах – один вариант использует указатели, второй вариант – ссылки.
3. Напишите программу, проверяющую и демонстрирующую правильность работы процедур.

## Task2
### Текст задания
Согласно варианту описать указанные классы (варианты распределяются преподавателем лично). Написать программу, использующую описанные классы: инициализация переменных (ввод пользователя), выполнение действий с экземплярами класса (в зависимости от дальнейшего ввода пользователя).
Описания и реализация должны находиться в разных файлах. Доступ к полям класса – только через методы. Внешние функции для работы с данными класса не допускаются. Перегрузка стандартных арифметических операций для класса (только в виде методов класса) – в зависимости от задания и здравого смысла (уместна консультация с преподавателем практики).
Дополнительно оценивается, если меню программы будет реализовано с помощью класса. Также возможно использование такого класса «меню» другого студента с указанием его авторства (использование чужого «меню», естественно, дополнительно не оценивается).

## Task3
### Текст задания
Согласно варианту описать указанные типы данных и поместить их в отдельный заголовочный файл, в нем же описать операторы, указанные в варианте. Реализацию функций поместить с отдельный cpp файл.
Написать программу, проверяющую правильность работы – для наглядности и лучшего усвоения материала использовать как явный, так и не явный метод вызова функций операторов (см. пример в конце задания).

## Task4
### Текст задания
Реализовать все указанные интерфейсы (абстрактные базовые классы) для
классов (согласно варианту):
1. Круг
2. Отрезок
3. Равносторонний треугольник
4. Прямоугольник
5. Шестиугольник
6. Параллелограмм
7. Равнобедренная трапеция
8. Эллипс (периметр можно считать по любой приближенной формуле: см. интернет, справочники и т.п.).

Функционал системы:
1. Хранение множества фигур
2. Динамическое добавление фигур пользователем. ​(через консоль)
3. Отобразить все фигуры.
4. Суммарная площадь всех фигур.
5. Суммарный периметр всех фигур.
6. Центр масс всей системы.
7.Память, занимаемая всеми экземплярами классов.
8. Сортировка фигур между собой по массе.

Вопросы для обдумывания:
1. Есть ли необходимость делать методы сравнения по массе виртуальными?
2. Получится ли также перегрузить операторы сравнения для интерфейса BaseCObject​ ​ чтобы сравнивать объекты по объему занимаемой памяти?
3. Предположите, что в дальнейшем придется изменить код таким образом, чтобы фигуры (оставаясь сами по себе плоскими) задавались уже не в двумерном, ​а в трехмерном пространстве. Укажите как бы вы действовали? Что пришлось бы ​​ изменить?

## Task5
### Текст задания
Написать шаблонную функцию или класс согласно варианту. Описать класс-исключение или иерархию классов-исключений. Генерировать исключения в соответствующих исключительных ситуациях. Если у вас есть другие предложения по исключительным ситуациям – используйте их.

## Task6
### Текст задания 
Требуется реализовать следующие обобщенные алгоритмы.
1. all_of - возвращает true, если все элементы диапазона удовлетворяют некоторому предикату. Иначе false
2. any_of - возвращает true, если хотя бы один из элементов диапазона удовлетворяет некоторому предикату. Иначе false
3. none_of - возвращает true, если все элементы диапазона не удовлетворяют некоторому предикату. Иначе false
4. one_of - возвращает true, если ровно один элемент диапазона удовлетворяет некоторому предикату. Иначе false
5. is_sorted - возвращает true, если все элементы диапазона находятся в отсортированном порядке относительно некоторого критерия
6. is_partitioned - возвращает true, если в диапазоне есть элемент, делящий все элементы на удовлетворяющие и не удовлетворяющие некоторому предикату. Иначе false.
7. find_not -​ находит первый элемент, не равный заданному
8. find_backward ​- находит первый элемент, равный заданному, с конца
9. is_palindrome - возвращает true, если заданная последовательность является палиндромом относительно некоторого условия. Иначе false.

Каждый алгоритм должен быть выполнен в виде шаблонной функции, позволяющей взаимодействовать со стандартными контейнерами STL с помощью итераторов. Предикаты, условия, операторы сравнения должны быть параметризованы.
При сдаче работы требуется продемонстрировать работу алгоритмов как на стандартных, так и на пользовательских типах данных, например CPoint, CRational, далее работает ваша индивидуальная (не “коллективная”) фантазия.

## Task7
### Текст задания
Реализовать к​ольцевой буфер в виде stl-совместимого контейнера (например, может быть использован с стандартными алгоритмами), обеспеченного итератором произвольного доступа.
Реализация не должна использовать ни одни из контейнеров STL.
Буфер должен обладать следующими возможностями:
1. Вставка и удаление в конец
2. Вставка и удаление в начало
3. Вставка и удаление в произвольное место по итератору
4. Доступ в конец, начало
5. Доступ по индексу
6. Изменение капасити
