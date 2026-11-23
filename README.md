# Лабораторная работа №2. Крупный ООП-проект

Предметная область: **пиццерия**. Модель описывает клиентов, сотрудников
(повара, официанты, курьеры, кассиры и др.), меню, заказы, оплату, доставку
и кухонное оборудование.

## Что реализовано

- иерархия сотрудников: базовый `Human`, рабочий `PizzeriaWorker`, повара,
  официанты, курьеры, кассиры, менеджер, бухгалтер, хостес и оператор
  call-центра;
- меню и рецепты: ингредиенты, пицца, комбо-наборы, категории меню;
- оформление заказа, смена статусов и контроль качества;
- оплата наличными, картой и через мобильное приложение, чеки, купоны и
  программа лояльности;
- доставка: адрес, зона, маршрут, расчёт стоимости и отслеживание статуса;
- кухня и склад: печь, холодильник, склад, поставщик и контроль качества;
- консольная демонстрация полного сценария работы пиццерии в `src/main.cpp`;
- собственные классы исключений для ошибок заказа, оплаты, доставки, склада
  и персонала.

## Структура проекта

- `include/` — объявления классов, сгруппированные по подсистемам
  (`common`, `human`, `menu`, `order`, `payment`, `delivery`, `kitchen`,
  `staff`, `pizzeria`);
- `src/` — реализации классов и консольная программа `main.cpp`;
- `tests/` — модульные тесты UnitTest++ (`tests.cpp`, `test_main.cpp`);
- `tools/coverage.py` — вспомогательный скрипт сводки покрытия;
- `CMakeLists.txt` — сборка библиотеки исходников, приложения и тестов.

## Сборка и запуск

```bash
sudo apt-get install cmake g++ libunittest++-dev
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build -j
./build/pizzeria
```

`./build/pizzeria` запускает консольную демонстрацию: наём сотрудников,
приём заказа, приготовление, оплату, доставку и отчёт о работе пиццерии.

## Тесты и покрытие

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug \
      -DCMAKE_CXX_FLAGS="--coverage" \
      -DCMAKE_EXE_LINKER_FLAGS="--coverage"
cmake --build build -j
./build/run_tests
gcovr --root "$PWD" --filter "$PWD/src/" --filter "$PWD/include/" \
      --exclude '.*/src/main.cpp' --fail-under-line 90 --print-summary
```

Тесты проверяют бизнес-логику всех подсистем: расчёт стоимости, скидки,
оплату, статусы заказов, работу кухни и склада, маршруты доставки, права
сотрудников и обработку исключений. Текущий результат — **118 тестов,
99,8 % покрытия строк** (897 из 899 строк, покрытие функций — 100 %).

## CI/CD

Workflow `.github/workflows/ci.yml` запускается при push в `main`, при
pull request и при создании тега `v*` и выполняет:

1. сборку проекта и запуск 118 модульных тестов;
2. проверку покрытия `gcovr` с порогом 90 % и публикацию XML-отчёта;
3. статический анализ `clang-analyzer` через `clang-tidy`;
4. сборку релизного бинарника `pizzeria`;
5. упаковку бинарника в архив и публикацию его в GitHub Releases при push
   тега `v*`.

Скачанный из Releases архив содержит самостоятельный исполняемый файл:

```bash
tar -xzf pizzeria-linux-x86_64.tar.gz
./pizzeria
```

## Соответствие количественным требованиям

| Требование | Минимум | В проекте |
|---|---|---|
| Классы | 50 | 54 |
| Поля | 150 | 158 |
| Уникальные поведения | 100 | 293 |
| Ассоциации | 30 | 34 |
| Собственные исключения | 12 | 15 |

## Модель классов

Формат строки: `Класс | число полей | число методов | связанные классы`.

| Класс | Поля | Методы | Ассоциации (связанные классы) |
|---|---|---|---|
| Accountant | 4 | 9 | — |
| CallCenterOperator | 4 | 7 | Pizza |
| CardPayment | 4 | 7 | Payment |
| CashPayment | 2 | 3 | Payment |
| Cashier | 3 | 7 | Payment |
| ComboSet | 3 | 7 | MenuItem |
| Coupon | 6 | 7 | — |
| Courier | 5 | 9 | DeliveryRoute |
| DeliveryAddress | 7 | 8 | — |
| DeliveryFeeCalculator | 2 | 3 | DeliveryZone |
| DeliveryRoute | 4 | 7 | DeliveryAddress |
| DeliveryTracker | 5 | 8 | — |
| DeliveryZone | 4 | 8 | DeliveryAddress |
| Exceptions | 1 | 2 | PizzeriaException, OrderException, PaymentException, DeliveryException, InventoryException, StaffException и др. |
| Hostess | 5 | 8 | — |
| Human | 3 | 5 | — |
| Ingredient | 6 | 8 | — |
| Intern | 3 | 7 | PizzeriaCooker |
| Kitchen | 3 | 8 | Oven, PizzeriaCooker, Order |
| LoyaltyProgram | 3 | 8 | — |
| MenuCatalog | 2 | 8 | MenuItem |
| MenuItem | 6 | 11 | — |
| MobilePayment | 3 | 5 | Payment |
| Order | 5 | 8 | Pizza |
| Oven | 6 | 9 | — |
| Payment | 3 | 9 | — |
| Pizza | 3 | 11 | Ingredient |
| PizzaDepartment | 11 | 12 | Pizza, PizzeriaWaiter, PizzeriaCooker, PizzeriaCookerIntern, PizzeriaWorker, Order, Human |
| PizzeriaClient | 3 | 4 | Pizza, PizzaDepartment |
| PizzeriaCooker | 3 | 6 | Order |
| PizzeriaCookerIntern | 1 | 5 | PizzeriaCooker, Order |
| PizzeriaManager | 5 | 11 | — |
| PizzeriaWaiter | 3 | 5 | Pizza, Order |
| PizzeriaWorker | 2 | 4 | PizzaDepartment |
| QualityController | 2 | 6 | Order |
| Receipt | 5 | 9 | MenuItem |
| Recipe | 5 | 9 | Ingredient |
| Refrigerator | 4 | 8 | Ingredient |
| Supplier | 5 | 8 | Ingredient |
| Warehouse | 4 | 9 | Ingredient |

### Исключения (15)

- PizzeriaException
- OrderException
- EmptyOrderException
- NoSuchOrderException
- PaymentException
- PaymentDeclinedException
- InsufficientFundsException
- DeliveryException
- NoCouriersAvailableException
- DeliveryZoneNotFoundException
- InventoryException
- ItemOutOfStockException
- StaffException
- PizzeriaWorker::DepartmentNotSetException
- PizzaDepartment::AllCooksAreBusyException

### Итоговая статистика

| Показатель | Значение |
|---|---|
| Классы | 54 |
| Поля | 158 |
| Поведения | 293 |
| Ассоциации | 34 |
| Исключения | 15 |