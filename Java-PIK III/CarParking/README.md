Направете клас описващ паркинг за МПС. Класът трябва да има член променливи за общият брой парко места(parking slot),ID на паркинга – string, масив за МПС които са паркирани на паркинга(низове с формат, обяснен на края на задачата).
Класът трябва да извършва функционалности:
Паркиране на ново МПС.(мпс-то се паркира на свободно място с определен номер, след което мястото се заема). Ако няма място да се подаде изключение (FullParkingException със съответно съобщение за запълването на паркинга). Направете функция Park, която да извършва гореописаното.

Връщане на броя всички паркоместа които има на всички създадени паркинги.
Връщане на броя всички паркоместа които са заети на всички създадени паркинги.

Извеждане на МПС от паркинга (конкретното МПС освобождава парко мястото и се премахва от масива с МПС)
 
Направете клас наследяващ паркинг – автомобилен паркинг.
В този паркинг имате обслужващ персонал, който паркира автомобилите – 5 души. Автомобил може да бъде паркиран само ако има свободен човек, който да го обслужи. Направете функция Park, която да извършва действието.
 
Направете клас наследяващ паркинг – паркинг за камиони.
В този паркинг  може да паркирате камиони без ремарке или с 1 и 2 ремаркета. Всяко ремарке заема едно допълнително място за паркиране. Направете функция Park, която да извършва действието.
в класа Truck имате метод GetSize(), който връща броя на ремаркетата, които има обекта.
 
 
На класа за автомобили се подава обект от тип Car, на класа за камиони обект от тип Truck. И двата обекта връщат низ с данни за автомобила който е от типа: Licence@model$year.  Чрез функцията ToString().
И двата класа не приемат и паркират коли, които не отговарят на даденото условие. При невалидност да се подаде изключение CarNotValid, което съобщава на потребителя “the car does not have the specifications needed for this parking”. 
Licence – 2 главни букви, последвани от 4 цифри последвани от 2 главни букви
Model – малки букви и цифри, не повече от 10 знака общо
Year – само цифри