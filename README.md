# :white_check_mark: Philosophers (project 2021)

## Как запустить:
```
make
./philo * * * * *
```
"*" это соответственно: <br>
\* количество философов <br>
\* время до смерти(от одного приёма прищи до другого) <br>
\* время на еду <br>
\* время на сон <br>
\* опционально, можно указать сколько приёмов пищи должно произойти <br>

## Описание
Проблема обедающих философов является классическим примером, классический пример, используемый в информатике для иллюстрации проблем синхронизации при разработке параллельных алгоритмов и техник решения этих проблем.

Задача была сформулирована в 1965 году Эдсгером Дейкстрой как экзаменационное упражнение для студентов. В качестве примера был взят конкурирующий доступ к ленточному накопителю. Вскоре задача была сформулирована Энтони Хоаром в том виде, в каком она известна сегодня.
### Постановка задачи
<img src="https://github.com/markveligod/philosophers-/raw/master/img/1.png" width="300">  
  
Пять безмолвных философов сидят вокруг круглого стола, перед каждым философом стоит тарелка спагетти. Вилки лежат на столе между каждой парой ближайших философов.

Каждый философ может либо есть, либо размышлять. Приём пищи не ограничен количеством оставшихся спагетти — подразумевается бесконечный запас. Тем не менее, философ может есть только тогда, когда держит две вилки — взятую справа и слева (альтернативная формулировка проблемы подразумевает миски с рисом и палочки для еды вместо тарелок со спагетти и вилок).

Каждый философ может взять ближайшую вилку (если она доступна) или положить — если он уже держит её. Взятие каждой вилки и возвращение её на стол являются раздельными действиями, которые должны выполняться одно за другим.

Вопрос задачи заключается в том, чтобы разработать модель поведения (параллельный алгоритм), при котором ни один из философов не будет голодать, то есть будет вечно чередовать приём пищи и размышления. 
  
## Difference between a semaphore and a mutex
|parameters|semaphore|Mutex|
|:--------:|:-------:|:---:|
|Mechanism|This is a type of signaling mechanism.|This is a locking mechanism.|
|Data type|A semaphore is an integer variable.|A mutex is just an object.|
|Modification|Wait and signal operations can change the semaphore.|It is only changed by the process that can request or release the resource.|
|Resource management|If no resource is available, the process requires a resource that must perform a wait operation. Wait until the semaphore counter is greater than 0.|If it is blocked, the process must wait. The process must be stored in a queue. This should only be accessed when the mutex is unlocked.|
|Thread|You can have multiple program threads.|You can have multiple program threads in a mutex, but not simultaneously.|
|Possession|The value can be changed by any process that releases or retrieves the resource.|An object's lock is released only by the process that received the lock for it.|  
|Types|Semaphore types are considered semaphore and binary semaphore|Mutex has no subtypes.|
|Operation|The semaphore value is changed using the wait() and signal() operations.|The mutex object is locked or unlocked.|
|Employment resources|It is busy if all resources are in use, and the process requesting the resource performs a wait () operation and blocks until the semaphore count is > 1.|If the object is already locked, the process requesting resources waits and is logged in by the system before releasing the lock.|

## Полезные ссылки:
[Такие удивительные семафоры](https://habr.com/ru/post/261273/)  
[Знакомство с межпроцессным взаимодействием на Linux](https://habr.com/ru/post/122108/)  
  
## Other
**Author:**  
*[Andrey Belenov](https://github.com/luchikAR)*
