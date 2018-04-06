# Portafolio del mes Noviembre

## Descripción del principio SOLID Open Closed y por qué la herencia no es la mejor solución para extender el software.

### Principio Open Closed

Para el portafolio del mes de noviembre tomé un [artículo](https://codeburst.io/understanding-solid-principles-open-closed-principle-e2b588b6491f) que habla sobre el principio SOLID Open Closed. Algo que llama la atención es que para extender el software mencionan que la herencia no es una buena práctica, si no que se debería usar composición, ¿ A qué se debe esto?.

Para contextualizar, el principio SOLID Open Closed tiene como idea principal que las entidades de software (clases, módulos, etc.) deben estar abiertas para extensión, pero cerradas para modificación. La idea de tener las entidades cerradas al cambio, radica en que en un principio el código funciona bien y presenta cohesión, por lo que modificar el código podría adulterar su funcionamiento y cohesión (se pueden incluir bugs o errores de diseño). El problema es que es natural necesitar extender el software para agregar nuevos requerimientos, por lo que la extensión debe ser de tal forma que no dañe las entidades existentes. Es por eso, que las entidades deben tener un carácter "inmutable", o sea, que no deben cambiar en el transcurso del diseño del software. La solución para agregar nuevas features es la extensión. ¿De qué forma se puede extender las entidades? El artículo propone extender en base a composición y no con herencia.

Para dar razones de porqué esto es beneficioso, basaré mi análisis en el siguiente  [artefacto](https://devexperto.com/herencia-vs-composicion/), que hace una comparación entre herencia y composición.

### Herencia

Herencia es cuando un objeto o clase se basa en otro objeto o clase, esto quiere decir que usa la misma implementación o comportamiento. La ventaja que entrega esto es que permite reutilizar código para hacer extensiones independientes, además, permite sobrescribir métodos, por lo que si algo no es exactamente como se necesita se puede volver a implementar

El problema de la herencia no es que sea mala por si misma, si no que se usa de mala manera. La herencia implica una relación "es un" o "ser", por lo que si una clase B hereda de A, quiere decir que B "es un" A. Cabe mencionar que el polimorfismo dará un comportamiento permanente a la clase derivada similar al de la clase padre.

Los desarrolladores confunden el concepto de "es un" con "tener", la relación "es un" es muy fuerte ya que es un comportamiento permanente. Lo que quiere decir esto es que si existe herencia, y volviendo al ejemplo de B hereda de A, B será de forma permanente (debido al polimorfismo) un A. Si bien se pueden editar los métodos de A (override), B será siempre un A. Lo que hay que destacar es la palabra "siempre", la cual es muy controversial en desarrollo de software ya que los requisitos pueden cambiar. El tema acá, es que no se puede comprometer al software a que una clase siempre va a tener un determinado comportamiento ya que puede cambiar, por lo que no se puede decidir de forma categórica al inicio del diseño del software las características finales que tendrán las entidades. 

Dado esto, la relación "es un" es demasiado estricta para los fines prácticos y los desarrolladores tienden a confundir la relación "es un" con la relación "tener", la cual tiene un carácter temporal. Dado que en el transcurso del desarrollo todo cambia, es difícil definir en las etapas iniciales del proyecto estructuras que serán permanentes en la aplicación (dado que hay mucha incertidumbre), por lo que hay que estar conscientes de que si se usa herencia, esta puede dejar de cumplirse en cualquier momento.

Hecho este análisis, se necesita una relación más débil que no sea permanente. Para esto existe composición.

### Composición

Composición se refiere a una instancia de una clase que contiene instancias de otras clases que implementan funciones deseadas, esto quiere decir que tareas que fueron asignados a un objeto se delegan a otro que si sabe hacerlas (por lo que también existe reutilización de código). 

La composición es una cualidad del objeto de carácter temporal, debido a que el objeto no está atado "para toda la vida" a delegar las tareas a otro objeto, podría incluso, cambiar la composición a otro objeto que haga las tareas mejor (la herencia no permitiría esto porque implementa una relación más fuerte). Es por eso que composición aplica la relación "tener" en vez de "es un", por lo que es apto para extender el software (permite más flexibilidad).

Otra de las ventajas de la composición sobre la herencia es que con composición se puede implementar solo lo que se desea y no se heredan funciones que no se necesitan.

Si bien la composición ofrece más flexibilidad y mejor diseño, tiene un costo en tiempo. Se requiere más clases y pensar de mejor forma el software para lograr las funcionalidades. Hay que considerar el principio SOLID de responsabilidad única para que cada entidad tenga solo una responsabilidad y ver de qué forma lograr la composición.

### Consideraciones a la hora de diseñar el código

Son muchos de los errores que ocurren al momento de diseñar el código, pero quiero destacar estos tres:

* Tener una idea con anticipación de cuales son los cambios futuros que se necesitarán hacer a las entidades para diseñarlas desde un principio de buena forma.
* Diseñar el código de forma que no haya que volver a escribirlo cuando cambien los requisitos. Las nuevas funcionalidades se pueden implementar agregando nuevas clases, reutilizando métodos, usando composición, entre otros.
* Borrar de la mente la palabra "siempre" ya que guía de forma equivocada en nuestra mente a “es un” y eso guía a herencia. Hay que definir si la relación es de carácter temporal o permanente, de forma de usar composición o herencia según sea necesario.





