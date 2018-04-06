# Portafolio del mes - Octubre

Para este portafolio considere un [artefacto](https://medium.freecodecamp.org/is-mvc-dead-for-the-frontend-35b4d1fe39ec) que habla de arquitecturas de clientes web. Específicamente comenta de por qué el éxito del modelo MVC en el servidor no pudo ser replicado en los clientes web (Single-page applications).

En un principio existían las Multiple-Page Applications, en la cual la responsabilidad de la lógica de la aplicación recaía en su totalidad en el servidor. La arquitectura que presentaba este tipo de aplicaciones era Model-View-Controller, donde existe un desacople de cada componente. Este desacople permite que, por ejemplo, un controlador pueda tener múltiples vistas.  

Con la aparición de los primeros frameworks de cliente, el componente View del MVC se trasladó al cliente, esto quiere decir que el servidor ya no envía assets (HTML, Javascript y CSS) con cada request.  Con esta nueva tecnología, en el primer request al servidor se envían todos los assets que podría llegar a necesitar el cliente, esto permite incorporar mucha más lógica y responsabilidades en el lado del cliente convirtiendo al servidor solo en una API para acceder a los datos.

Para poder construir un software de cliente web es necesaria una arquitectura. El paso lógico era replicar la exitosa arquitectura de servidor MVC en el cliente, pero esto no dio un buen resultado. El principal problema que experimentó la inclusión del MVC en el cliente es que la separación de responsabilidades del servidor son distintas a las del cliente. Por ejemplo, controlador y la vista en el cliente no tenían las mismas responsabilidades que en el lado del servidor. En el cliente existe un mayor acoplamiento entre la vista y el controlador, es tanta la dependencia que la relación vista-controlador es 1-1, lo que permite dar mucha lógica a un componente web. La ventaja de este tipo de acoplamiento es que se permite, por ejemplo, el [two-way data binding](https://victorroblesweb.es/2016/06/04/two-way-data-binding-angular-2/) presente en algunos frameworks.

Por otro lado, en el lado del cliente existen dos estados/modelos; el modelo de datos de la aplicación y el estado de los componentes (el cual hace referencia al conjunto de datos y variables que definen el comportamiento de un componente en un momento dado, como por ejemplo si una ventana modal está abierta o cerrada). Aquí también se viola el principio de Responsabilidad Única en la arquitectura MVC, ya que el modelo estaría almacenando tanto el estado de la aplicación como de los componentes.

Dado este análisis, la respuesta de por qué fallo MVC en el cliente es que se violaba el principio Solid de Responsabilidad Única, donde el controlador del lado del cliente está cumpliendo una función para la cual no está diseñado en la arquitectura MVC (lógica del negocio e intermediario para la vista). Además, el modelo en el cliente tiene dos responsabilidades cuando debería tener solo una. Con el tiempo se dio paso a distintas arquitecturas que se han ido perfeccionando en el tiempo (Model-View-ViewModel, Model-View-Presenter, Redux, Flux, entre otros), las cuales tienen un diseño mejor desde el punto de vista de los principios SOLID.

Dado esto, vale la pena destacar dos aspectos:

1. El acoplamiento no es malo, incluso a veces es necesario: en el caso de las arquitecturas de frontend, el alto acoplamiento entre el controlador y la vista permite añadir funcionalidades que si existiera bajo acoplamiento no serían fáciles de implementar (two-way data binding). Además, el alto acoplamiento permite que los componentes web tengan encapsulado todo el comportamiento, de forma que los componentes web se pueden exportar a otros proyectos y reutilizar el componente.
2. Los principios SOLID van mucho más allá que el diseño de programación orientada a objetos, son lineamientos para el diseño del software: en este caso, el principio SOLID de responsabilidad única es el motivo por el cual se dejó de usar MVC en el cliente. El hecho de tener más de una responsabilidad en los componentes MVC genera problemas en el diseño. Cabe mencionar que la responsabilidad es el eje del cambio, por lo que si cambian las responsabilidades debe haber cambio en el componente. En este caso al tener más de una responsabilidad en el componente (el controlador tiene dos responsabilidades), debe haber un cambio en el diseño.












