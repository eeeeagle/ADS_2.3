Лабораторная  работа  должна  быть  выполнена  на  одном  из  трёх  уровней  сложности.  Уровень сложности выбирается самостоятельно с учётом следующих ограничений: 

|**На каком уровне сдана вторая лабораторная?** |**Какой уровень вы можете взять** |
| :- | - |
|Низкий |<p>Низкий </p><p>*Для среднего/высокого нужно получить явное разрешение у преподавателя* </p>|
|Средний |<p>Низкий, средний </p><p>*Для высокого нужно получить явное разрешение преподавателя* </p>|
|Высокий |Любой |

Алгоритмы обхода и поиска кратчайшего пути реализовать согласно своему варианту. Реализуемые алгоритмы определяются цифрами представления вашего номера варианта в системе счисления по основанию 2. 

|**Алгоритм обхода** |**Алгоритм поиска кратчайшего пути** |
| - | - |
|<p>0. В ширину </p><p>1. В глубину </p>|<p>0. Алгоритм Дейкстры </p><p>1. Алгоритм Беллмана-Форда </p>|

**Пример.** Допустимый набор вариантов 0—3 (002—112). Предположим, что вам назначен вариант 1. Представим это число в системе счисления с основанием 2: 1 = 0·21 + 1·20 = 012. Таким образом, в 1-ом варианте необходимо реализовать алгоритм обхода в ширину и алгоритм Беллмана-Форда. 

**Минимальный уровень сложности** 

Разрешено использование любых STL-контейнеров и функций из <algorithm>. Использование любых механизмов по ручному управлению памяти (alloc/free, new/delete) и указателей запрещено. 

1. Реализовать класс для описания населённого пункта. Состояние, как минимум, должно описываться названием населённого пункта и количеством жителей. 
1. Реализовать  класс  для  работы  с  дорожной  сетью  в  виде  ориентированного  графа  (способ представления графа выбрать самостоятельно), где вершины представляют собой населённые пункты, а рёбра – информацию о длинах дорог. На данном шаге необходимо реализовать инфраструктурные методы для работы с графом: добавление и удаление вершин и ребер, отладочный вывод. Отладочный вывод графа должен выводить максимально детальную информацию о текущем состоянии структур данных, выбранных для представления графа. Выводимая отладочная информация должна исключать любую возможность неоднозначной интерпретации. 

**Пример.** Например, для представления графа выбран список смежности. В этом случае недостаточно просто вывести сплошным списком все рёбра графа. При отладочном выводе должна быть видна **структура**  списка  смежности:  для  каждой  выведенной  вершины  должен  отображаться  отдельный список смежных вершин [рёбер]. 

3. Реализовать алгоритм обхода согласно своему варианту. 
3. Реализовать  алгоритм  поиска  кратчайшего  пути  между  двумя  заданными  вершинами  согласно своему  варианту.  Алгоритм  должен  возвращать  найденный  путь  в  виде  набора  вершин  (включая начальную и конечную вершины пути). 
3. Подготовить [захардкодить] достаточно разветвлённый граф для демонстрации. 

**Средний уровень сложности**

*Тезисно: абстрагирование алгоритмов на графах от конкретной семантики в виде дорожной сети.* 

1. Класс ориентированного графа должен быть шаблонным и не должен ничего знать о том, какие типы выступают  в  качестве  вершин  и  рёбер.  За  тип  вершин  и  тип  рёбер  должны  отвечать  шаблонные аргументы TVertex и TEdge соответственно. 
1. Предполагать,  что  объекты  типа  TVertex  **допускают  сравнение**,  то  есть  допустимы  конструкции следующего вида: vertex1 == vertex2 и vertex1 != vertex2. 
1. Предполагать,  что  объекты  типа  TEdge  **допускают  приведение  к  вещественному  типу**,  то  есть допустима конструкция следующего вида: static\_cast<double>(edge). 
1. Продемонстрировать работу класса на примере дорожной сети, где каждая дорога описывается не только длиной, но и некоторой дополнительной информацией на свой выбор (например: имеет ли дорога статус федеральной, является ли дорога платной и т. п.). На среднем уровне сложности эта дополнительная информация никак не влияет на алгоритм поиска кратчайшего пути. 

**Высокий уровень сложности** 

*Тезисно: дальнейшее абстрагирование в виде уменьшений требований к типам TVertex и TEdge.* 

1. К типу TVertex  не  должны  предъявляться  никакие  требования,  кроме  copyable  и  destructable.  В частности,  тип  **может  не  допускать  сравнение**.  Потенциальное  отсутствие  операторов  сравнения можно  обойти  дополнительными  шаблонными  аргументами  класса  графа  со  значениями  по умолчанию, равными std::equal\_to<?>. 
1. К  типу  TEdge  не  должны  предъявляться  никакие  требования,  кроме  copyable  и  destructable.  В частности, тип **может не допускать приведения к вещественному типу**. Потенциальное отсутствие конвертируемости TEdge можно обойти шаблонизацией соответствующего метода с указанием типа так называемого селектора, позволяющего произвести необходимую конвертацию:  

```cpp
template<typename TWeightSelector> 
void Method(…, TWeightSelector weightSelector) 
{
  TEdge edge = …; 
  double weight = weightSelector(edge); 
  … 
} 
```

3. Для методов, подпадающих под пункт 2, предусмотреть перегрузку, которая не требует указания селектора. В этом случае поведение метода должно откатываться к попытке прямого приведения к вещественному  типу  через  static\_cast.  Разумеется,  дублирование  алгоритмов  недопустимо  и реализация данной перегрузки должна сводиться к вызову шаблонного метода с селектором из п. 2. 
3. Продемонстрировать работу на следующем примере. Дорога между населёнными пунктами должна описываться как минимум: длиной, типом (асфальт/грунт) и платностью (платно/бесплатно). Показать, что теперь возможно вычислять вес маршрута между населёнными пунктами с учётом типа дороги и платности (в этом случае пользователем должны задаваться штрафные коэффициенты для грунтовых и платных дорог). См. пример на следующей странице. 

**Пример для высокого уровня сложности** 

Пусть дан следующий граф: 

![graph_example](https://user-images.githubusercontent.com/90867530/194729253-54fc36ea-2c3d-4461-8585-f3a06c1f9185.png)

При поиске кратчайшего пути вес маршрута между А и Г может оцениваться различными способами в зависимости  от  желаний  пользователя,  выражаемых  в  виде  установки  значений  штрафных коэффициентов. Примеры: 

|Значения штрафных коэффициентов |Итоговый вес |
| - | - |
|<p>За грунтовую дорогу: 1 </p><p>За платность: 1 </p><p>Единичные коэффициенты эквивалентны использованию алгоритма  из  среднего  уровня  сложности,  когда особенности дорог никак не влияют на вес маршрута. </p>|20 + 5×1 + 10×1 = 35 |
|За грунтовую дорогу: 1,5 За платность: 1 |20 + 5×1 + 10×1,5 = 40 |
|За грунтовую дорогу: 1,5 За платность: 10 |20 + 5×10 + 10×1,5 = 85 |

В случае платной грунтовой дороги обеспечить мультипликативный эффект штрафных коэффициентов. 

____

__Работа не выполнена__: отсутствует алгоритм Дейкстры и не работает алгоритм обхода в ширину.

Работа выполнялась на средний уровень
