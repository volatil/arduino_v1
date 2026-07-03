# Instrucciones para Codex

Este repositorio es una coleccion de sketches Arduino. La estructura todavia puede evolucionar, asi que Codex debe preservar el orden existente y hacer cambios pequenos, claros y faciles de revisar.

## Contexto del proyecto

- Trata cada carpeta o sketch como una pieza potencialmente independiente hasta que el repositorio defina una organizacion mas precisa.
- No impongas una estructura rigida por tema, placa o componente sin que Paulo lo pida.
- Si creas una estructura nueva, mantenla simple, explicable y consistente con lo que ya exista.
- Antes de editar, lee el contexto relevante: sketches, notas, librerias declaradas, configuracion y archivos cercanos.
- Evita refactors no pedidos y cambios cosmeticos extensos que dificulten revisar la intencion real.

## Hardware base

La placa objetivo por defecto es un Arduino UNO R4 WiFi compatible. Si un sketch o una instruccion especifica otra placa, respeta esa indicacion local.

Caracteristicas relevantes:

- Microcontrolador Renesas RA4M1, Arm Cortex-M4 a 48 MHz.
- 256 KB de Flash y 32 KB de RAM.
- WiFi y Bluetooth integrados mediante modulo ESP32-S3.
- Matriz de LEDs integrada de 12 x 8.
- 14 pines de E/S digital, con 6 salidas PWM.
- 6 entradas analogicas con resolucion de 14 bits.
- 1 canal DAC de 12 bits.
- Comunicacion UART, I2C, SPI y CAN Bus.
- Conector USB-C para programacion y alimentacion.
- Voltaje de operacion de 5 V, con tolerancia de entrada hasta 24 V.

Kit de componentes disponible:

- Placa Arduino UNO R4 WiFi compatible.
- Protoboard 830 modelo MB-102.
- Cables macho-macho flexibles de diferentes medidas.
- 10 cables macho-hembra de 20 cm.
- Pack de resistencias, 20 piezas.
- Teclado matricial 4 x 4 rigido.
- Motor paso a paso 28BYJ-48.
- Controlador de motor paso a paso basado en IC ULN2003.
- Modulo RTC DS1307 I2C.
- Modulo joystick de 2 ejes.
- Lector RFID RC522 con tag y tarjeta S50.
- Receptor IR y control remoto IR.
- 3 fotorresistencias LDR 5528.
- Conector de bateria 9 V con jack para Arduino.
- Servo motor mini SG90 con accesorios.
- Potenciometro tipo perilla.
- 2 sensores de inclinacion SW-520D.
- Sensor de temperatura analogico lineal LM35.
- Fotodiodo receptor IR.
- 4 pulsadores PCB con cubierta de colores.
- Display de 7 segmentos.
- Display de 7 segmentos de 4 digitos.
- 15 LEDs 5 mm difusos, rojos, verdes y amarillos.
- LCD alfanumerico 2 x 16.
- Modulo de rele de 1 canal 5 V.
- Modulo LED RGB.
- Modulo matriz LED 8 x 8.
- Circuito integrado registro de desplazamiento 74HC595.
- Sensor de temperatura y humedad DHT11.
- Modulo sensor de nivel de agua/lluvia.
- Modulo sensor de nivel de sonido.
- Buzzer activo.
- Buzzer pasivo.

## Supuestos y decisiones

- Si falta informacion sobre placa, sensores, actuadores, librerias, puertos, baud rate, entorno Arduino o version de herramientas, documenta el supuesto antes de avanzar.
- Usa Arduino UNO R4 WiFi como placa objetivo por defecto; para APIs especificas de otra placa o core Arduino, pide confirmacion o infiere solo cuando el repo entregue evidencia clara.
- Antes de proponer conexiones, verifica compatibilidad electrica, pines requeridos, alimentacion y resistencias necesarias para los componentes involucrados.
- Si una decision puede afectar hardware conectado, dependencias o configuracion global, pide autorizacion explicita antes de actuar.
- Cuando uses Arduino CLI u otra herramienta, deja claro el comando, la placa objetivo, el puerto y cualquier supuesto relevante.

## Permisos y limites

Codex puede crear o modificar archivos normales del repositorio cuando Paulo pida una tarea concreta. Debe pedir autorizacion explicita antes de:

- Flashear, subir o ejecutar codigo en una placa.
- Instalar librerias, herramientas, cores, drivers o dependencias.
- Cambiar configuracion global de Arduino, puertos, drivers, variables de entorno o ajustes del sistema.
- Borrar, mover masivamente o reorganizar archivos.
- Ejecutar comandos que puedan afectar hardware conectado.
- Realizar acciones externas o publicar informacion fuera del entorno local.

## Calidad y verificacion

- Prefiere verificacion no destructiva: revisar compilacion, sintaxis, dependencias y configuracion antes de sugerir carga a hardware.
- Mantiene los sketches legibles, con nombres claros y comentarios breves solo cuando aclaren conexiones, pines o comportamiento no obvio.
- No introduzcas credenciales, tokens, nombres reales de redes Wi-Fi, claves o secretos en sketches. Usa placeholders o archivos ignorados si hace falta.
- Si no puedes verificar algo porque falta placa, puerto, libreria o herramienta, dilo claramente y explica que verificacion queda pendiente.

## Comunicacion externa

- Nunca envies, respondas, edites, borres, programes, reacciones ni publiques mensajes de Slack sin autorizacion explicita de Paulo para esa accion especifica.
- El permiso para investigar, buscar, leer Slack o "encargarse" de algo no autoriza ninguna accion de escritura en Slack.
