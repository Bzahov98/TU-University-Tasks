**Условие:**

Два  процеса  четат  масив  от  числа  от  даден  файл, сортират  този  масив  (с  два различни  алгоритъма,  по  Ваш  избор):

* Quick sort
* Merge sort

**Първият  процес**,  който  приключи,  извежда масива  на  екрана  и  прекъсва  другия  процес.  

КР: Да  се имплементират многонишкови сортировки.

Документацията може да бъде намерена [тук](https://docs.google.com/document/d/1nYf-TwlZgHE12s-IVyTqvUwFbESayVNC5K1Iyws5gbM/edit?usp=sharing)
Uml data class diagram може да бъде намерена [тук](https://app.lucidchart.com/invitations/accept/7ea736cf-abfe-49be-838a-e1233aedfb36)
Uml Sequence Diagram може да бъде намерена [тук](https://www.websequencediagrams.com/?lz=dGl0bGUgTXVsdHlQcm9jZXNzU29ydGluZ1Byb2dyYW0KYWN0b3IgAAYIAA8HIC0-IFBhcmVudAAuByA6IHN0YXJ0IHAAIQgAEQ0tPiBDb211bmljYXRpb25QaXBlIDogY3JlYXRlUGlwZQphY3RpdmF0ZQBHDwoKADgRKiBRdWlja0NoaWxkAHMKZm9yaygpIFxuZm9yayBmaXJzdCBjaGlsZCBwAIFQBgA1E01lcmdlACsdc2Vjb25kADoPAIB_E0ZpbGVVdGlscyA6IHJlYWRGaWxlRGF0YUZyb21GaWxlKCkKABkKAIIqEQAwBXR1cm4AQwUgRGF0YSAKZGVzdHJveQBQCwCCLiV3cml0ZSgpXG4ABAUgZGF0YSB0byBwAIJXDQCCexAKAIJAEi0-AIJSFXdhaXQgZm9yAFMGaW4AUwYAg0oRLQAoF3JlYWQAgyEFAIIhBSBpbnB1dACBHwUAg3YKAINLEgoKAIMXEi0-AIMpFQCBChUgZnJvbQCBEhcAgSUFAIN0FACBERkAQwsAhSsJAIQ4EQoAgj0VAIUzB1NvcnRBbGdvcml0aG0gOiBleGVjdXRlIHF1aWNrc29ydCBhABYIAIIIDwAtDQCCARYAhU8HAC81ACgSCgCBQgcAgSUOAINEGQCFPwVyZXN1bHQgdG8gc29ydGVkAINaBmRlAIEwGwCFZAoACBQAiDsQAIhoE3dhaXQoTnVsbACEVwUAhSAFdW50aWwgb25lAId5CCBmaW5pc2gAfgwAiFwQAIV0EwCJVRNleGl0KEVYSVRfU1VDQ0VTU0ZVTExZX0ZpcnN0X1NPUlRfRklSU1QpCgCJPBkAgWENAIQrDQCKJREAilUQY2hlY2sgUgCIKQZTdGF0dXMgXG4AhV0GAIlxBUV4aQCJcwcKAIg7CQCKahEAVRMAi1EHAIg7BwCDOgV0ZE91dACDSAgAiEUFAIJ4EwCKMRRraWxsAIdhBmtpbGwAij0Jb21wbGV0ZQCLCgkgd2l0aCAAKAYAiycFX2IsIFNJR0tJTEwpOwCHYhQAh28IAIYzEHRlcm1pbmF0ZSBjdXJyZW50IGl0ZXIAjGYFcwCKQQkAhUwTAE0WAINQIV9LSUxMRUQpAE0OAIdzDgCDKSEAhDYRAIoTBQCCHQgAjkAIIHN1Y2Nlc3NmdWxseQCDGxxzdG9wAI50CQCMNQgAjj0Q&s=qsd)

Интерпретация:
    Да се имплементира конзолно приложение, което да използва системните функции на Линукс(Linux/Unix) базираните операционни системи. То трябва да чете масив от числа от даден файл и да го сортира, чрез два различни многонишкови сортиращи алгоритъма. 
Това трябва да става паралено, като двата алгоритъма се изпълняват в два дъщерни(child), на основния процес на програмата(parent), независимо един от друг.  
Комуникацията между основния и неговите дъщерни процеси трябва да става чрез еднопосочна тръба (Pipe). Основният процес изчаква, единият от двата дъщерни процеса да завърши задачата си успешно и тогава убива другия дъщерен процес, който не е завършил поставената му задача. 
Единият дъщерен процес ще имплементира многонишковият алгоритъм за обединение (Merge Sort), а другият паралелен алгоритъм е за Бързо сортиране (Quick sort). Всеки от тези процеси ще следи времето му необходимо за изпълняване на същинската част на алгоритъма. 
