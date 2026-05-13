# Laboratorio 2: Sistemas Embebidos - TouchPad, WiFi y Servidor Web

**Autor:** Bruno Moreira Delfino  
[cite_start]**Institución:** Universidad Católica del Uruguay (Facultad de Ingeniería y Tecnologías) [cite: 2, 3]

## Descripción del Proyecto
[cite_start]Este repositorio contiene el código correspondiente al Laboratorio 2 de la asignatura Sistemas Embebidos[cite: 1]. [cite_start]El objetivo de este proyecto es la configuración y control de diversos periféricos utilizando las APIs nativas de ESP-IDF (esp_wifi, esp_netif, event loop y esp_http_server)[cite: 12]. 

[cite_start]El sistema final permite la interacción física a través de botones capacitivos y el control remoto mediante una interfaz web accesible desde cualquier navegador[cite: 9, 11].

## Hardware Requerido
* [cite_start]**Placa Base:** ESP32-S2-KALUGA-1 [cite: 5]
* [cite_start]**Placa de Extensión:** ESP-LyraP-TouchA v1.1 [cite: 5]

## Características Principales

1. **Lectura de Botones Capacitivos (TouchPad):**
   * [cite_start]Encapsulamiento del hardware en una librería propia (`components/touchpad`)[cite: 39].
   * [cite_start]Detección del estado de los 6 botones capacitivos de la placa de expansión mediante la técnica de polling[cite: 38].
   * [cite_start]Modificación del estado del LED RGB (color, brillo, encendido/apagado) dependiendo del botón presionado[cite: 45].

2. **Conectividad WiFi:**
   * [cite_start]**Modo AP (Access Point):** El ESP32-S2 despliega su propia red WiFi, permitiendo conexiones directas de clientes externos[cite: 64].
   * [cite_start]**Modo STA (Station):** El dispositivo actúa como cliente, conectándose a una infraestructura de red WiFi existente en el laboratorio[cite: 77, 79].

3. **Servidor Web y Control Remoto:**
   * [cite_start]Servidor HTTP embebido que aloja una interfaz web (HTML, CSS, JS) integrada directamente en el archivo binario mediante la directiva `EMBED_FILES`[cite: 89, 98].
   * [cite_start]Comunicación bidireccional cliente-servidor mediante solicitudes asíncronas (`fetch()`)[cite: 130].
   * [cite_start]API REST con endpoints `GET /led` y `POST /led` para consultar y modificar el estado del LED utilizando estructuras de datos JSON (procesadas mediante cJSON)[cite: 121, 124, 132].

4. **Integración Completa:**
   * [cite_start]Consistencia de estado: Los cambios efectuados físicamente mediante el TouchPad se ven reflejados en la interfaz web, asegurando que ambas interfaces de control operen en armonía[cite: 139, 140, 143].

## Estructura del Repositorio
[cite_start]El repositorio contiene dos proyectos principales de ESP-IDF[cite: 147]:
* [cite_start]`/Laboratorio_2a`: Implementación inicial enfocada únicamente en el control por TouchPad[cite: 27, 148].
* [cite_start]`/Laboratorio_2b`: Proyecto integrador con la gestión de conectividad WiFi, el servidor HTTP y la interfaz web[cite: 53, 158].
