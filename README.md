# Лабораторная работа №2. Крупный ООП-проект

Предметная область: **пиццерия**. Модель описывает клиентов, сотрудников
(повара, официанты, курьеры, кассиры и др.), меню, заказы, оплату, доставку
и кухонное оборудование.

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