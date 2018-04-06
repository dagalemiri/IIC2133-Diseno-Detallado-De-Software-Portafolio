#Principios SOLID #1: Single Responsibility Principle

El artefacto que utilicé proviene de la siguiente [pagina web](http://anexsoft.com/p/170/solid-1-single-responsibility-principle-srp-con-c). Este corresponde a un código en C# donde se muestra un ejemplo donde un código no aplica el principio SOLID de única responsabilidad.

Este principio dice que los módulos del software deben tener una sola responsabilidad, lo quiere decir que si existen múltiples responsabilidades en un módulo hay que buscar alguna forma de separar el código.

A modo de ejemplo se tiene el siguiente código:


```c#
class UserService
{
    public bool PayMyDebts(string userID)
    {
        var success = false;

        // El usuario necesita saber si tiene dinero en el banco para cubrir su deuda del mes
        if (HasMoneyAtBank(userID))
        {
            // El usuario va a pagar sus deudas para el mes actual
            success = true;
        }

        return success;
    }

    public bool HasMoneyAtBank(string userId)
    {
        return true;
    }
}
```

Esta clase tiene dos responsabilidades, ver si existe dinero en el banco y pagar cuentas. El problema que presenta este código es que tiene múltiples funcionalidades en vez de solo una, por lo que está violando el principio SOLID de única responsabilidad. El problema que puede traer esto es que se hace más difícil escalar y mantener el software, por lo que es necesario intervenir de modo de diseñar el código de mejor manera.

Para solucionar este problema se deben separar las responsabilidades, lo más lógico es separar en responsabilidad del banco y responsabilidad del usuario. La primera implica decir cuanto dinero tiene el usuario mientras que la segunda implica poder pagar las cuentas.

El código bien diseñado es el siguiente:


```c#
class UserService
{
    private readonly BankService _bankService;

    public UserService(BankService bankService)
    {
        _bankService = bankService;
    }

    public bool PayMyDebts(string userID)
    {
        var success = false;

        // El usuario necesita saber si tiene dinero en el banco para cubrir su deuda del mes
        if (_bankService.HasMoneyAtBank(userID))
        {
            // El usuario va a pagar sus deudas para el mes actual
            success = true;
        }

        return success;
    }


}

class BankService
{
    public bool HasMoneyAtBank(string userId)
    {
        return true;
    }
}
```

En este código se puede ver como se separan las responsabilidades de forma que no existan dependencias.
