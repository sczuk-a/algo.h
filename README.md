# Algoritmická knihovna `algo.h`

---

## Funkce

```cpp
T Max<T>(T a, T b)
T Min<T>(T a, T b)
```

Vrátí větší/menší z 2 prvků na vstupu. 
Parametr `T` musí mít definované operátory `>`,`<`.

```cpp
int MaxIdx<T>(T* arr, int i, int j)
int MinIdx<T>(T* arr, int i, int j)
```
Na vstupu obdrží pole `arr` a 2 indexy a vrátí ten, jehož hodnota v poli je větší/menší.
Parametr `T` musí mít definované operátory `>`,`<`.

```cpp
T ArrMax(T* arr, int len, int* max_idx = NULL)
T ArrMin(T* arr, int len, int* max_idx = NULL)
```
Na vstupu obdrží pole `arr`, jeho délku a vrátí maximální/minimální prvek pole. `max_idx`/`min_idx` je volitelný
parametr a pokud je s ním funkce zavolaná, uloží do něj index maximálního/minimálního prvku.
Parametr `T` musí mít definované operátory `>`,`<`.


```cpp
void ArrSwap<T>(T* arr, int i, int j)
```
Na vstupu obdrží pole `arr` a 2 indexy, jejichž hodnoty v poli prohodí.

```cpp
void ArrHeapSort<T>(T* arr, int len, bool rising = true)
```

Na vstupu obdrží pole `arr`, jeho délku `len` a volitelný parametr `rising` udávající směr třídění (`true` pro vzestupné,
`false` pro sestupné). Funkce pole setřídí pomocí algoritmu heap sort.
Parametr `T` musí mít definované operátory `>`,`<`, `=` a musí být pomocí nich lineárně uspořádaný.

Časová složitost: `O(nlog(n))`, kde `n` značí počet prvků pole.
Prostorová složitost: `O(1)`


```cpp
void ArrMergeSort<T>(T* arr, int len)
```
Na vstupu obdrží pole `arr`, a jeho délku `len`. Funkce pole setřídí pomocí algoritmu merge sort.
Parametr `T` musí mít definované operátory `>`,`<`, `=` a musí být pomocí nich lineárně uspořádaný.

Časová složitost: `O(nlog(n))`.
Prostorová složitost: `O(nlog(n))`, kde `n` značí počet prvků pole.



```cpp
void CountSort(int* arr, int len)
```
Na vstupu obdrží pole integerů `arr`, a jeho délku `len`. Funkce pole setřídí pomocí algoritmu count sort.


Časová složitost: `O(n + m).
Prostorová složitost: `O(m)`, kde `n` značí počet prvků pole a `m = Max(arr)-Min(arr)`.


```cpp
bool BinarySearch<int>(T* arr, T target, int beg, int end) 
```
Na vstupu obdrží setříděné pole `arr`, hledaný prvek `target` a 2 indexy. Vrátí `true`, pokud se hledaný prvek nachází v
poli mei danými indexy, jinak `false`. 
Parametr `T` musí mít definované operátory `>`,`<`, `=` a musí být pomocí nich lineárně uspořádaný.

## Datové struktury

### Jednostranný spojový seznam

```cpp
SinglyLL<T>
```

Jednostranný spojový seznam, pro data typu `T`.

```cpp
void SinglyLL<T>::Append(T data) 
```

Připojí `data` na konec seznamu.


```cpp
void SinglyLL<T>::Insert(T data) 
```

Připojí `data` na začátek seznamu.

```cpp
T SinglyLL<T>::RemoveFirst()
```

Odstraní první prvek seznamu a vrátí ho.

```cpp
void SinglyLL<T>::Clear()
```

Odstraní všechny prvky seznamu.

```cpp
bool SinglyLL<T>::IsEmpty()
```

Vrátí `true`, pokud je seznam prázdný, jinak `false`.

```cpp 
int SinglyLL<T>::Length()
```

Vrátí počet prvků v seznamu.


### Oboustranný spojový seznam

```cpp
DoublyLL<T>
```

Vše co jednostranný seznam.

```cpp
T DoublyLL<T>::RemoveLast()
```

Odstraní poslední prvek seznamu a vrátí ho.

### Fronta (FIFO)

```cpp
FIFO<T>
```

```cpp
void FIFO<T>::Insert(data T)
```

Přidá `data` do fronty.

```cpp
T FIFO<T>::Remove()
```

Odstraní poslední prvek z fronty a vrátí ho.

```cpp
bool FIFO<T>::IsEmpty()
```

Vrátí `true`, pokud je fronta prázdná, jinak `false`.


### Zásobník (LIFO)

```cpp
LIFO<T>
```

```cpp
void LIFO<T>::Insert(data T)
```

Přidá `data` do zásobníku.

```cpp
T FIFO<T>::Remove()
```

Odstraní první prvek ze zásobníku a vrátí ho.

```cpp
bool FIFO<T>::IsEmpty()
```

Vrátí `true`, pokud je zásobník prázdný, jinak `false`.

### AVL strom

```cpp
AVLTree<T>
```

Parametr `T` musí mít definované operátory `>`,`<`, `=` a musí být pomocí nich lineárně uspořádaný.
Binární vyhledávací strom, kde pro každý vrchol platí `|height(left) - height(right)| <= 1`. Pro zachovávání vlastností AVL stromu se používají rotace.

```cpp
void AVLTree<T>::Insert(T data);
```

Přidá `data` do stromu.

Časová složitost: O(log(n)), kde `n` je počet prvků stromu.


```cpp
void AVLTree<T>::Remove(T data);
```

Odebere `data` ze stromu.

Časová složitost: O(log(n)), kde `n` je počet prvků stromu.


```cpp
bool AVLTree<T>::Find(T data);
```

Vrátí `true`, pokud se `data` nachází ve stromu, jinak `false`.

Časová složitost: O(log(n)), kde `n` je počet prvků stromu.

### AB strom

```cpp
ABTree<T>(int _a, int _b)
```

Parametr `T` musí mít definované operátory `>`,`<`, `=` a musí být pomocí nich lineárně uspořádaný.

Vícecestný vyhledávací strom. Všechny vrcholy, vyjma kořene, mají `a` až `b` klíčů. Všechny externí vrcholy jsou uložené v
jedné vrstvě. Kořen má 1 až `b` klíčů.

Při přidávání a odebírání vrcholů vlastnosti zachovávají pomocí rozdělování/spojování vrcholů, které mají moc/málo
klíčů.



```cpp
void ABTree<T>::Insert(T data)
```

Vloží `data` do stromu. 

Časová složitost: `O(log(n))`, kde `n` je počet prvků ve stromě.


```cpp
void ABTree<T>::Remove(T data)
```

Odstraní `data` ze stromu. 

Časová složitost: `O(log(n))`, kde `n` je počet prvků ve stromě.


```cpp
bool ABTree<T>::Find(T data)
```

Vrátí `true`, pokud se `data` nacházejí ve stromě, jinak `false`. 

Časová složitost: `O(log(n))`, kde `n` je počet prvků ve stromě.

---

`tests.cpp` obsahuje několik testů na většinu algoritmů a datových struktur.

---

Většina použitých algoritmů pochází z přednášek k předmětu NTIN060 na MFF UK.

Antonín Beňa
Vytvořeno jako zápočtový program pro předmět NPRG031 na MFF UK.
LS 2020/21
