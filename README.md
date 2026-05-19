# Laboratorio 2: Sistemas Embebidos - TouchPad, WiFi y Servidor Web

**Autor:** Bruno Moreira Delfino  
**Institución:** Universidad Católica del Uruguay (Facultad de Ingeniería y Tecnologías)

## Descripción del Proyecto
Este repositorio contiene el código correspondiente al Laboratorio 2 de la asignatura Sistemas Embebidos. El objetivo de este proyecto es la configuración y control de diversos periféricos utilizando las APIs nativas de ESP-IDF (esp_wifi, esp_netif, event loop y esp_http_server). 

El sistema final permite la interacción física a través de botones capacitivos y el control remoto mediante una interfaz web accesible desde cualquier navegador.

## Hardware Requerido
* **Placa Base:** ESP32-S2-KALUGA-1
* **Placa de Extensión:** ESP-LyraP-TouchA v1.1

## Características Principales

1. **Lectura de Botones Capacitivos (TouchPad):**
   * Encapsulamiento del hardware en una librería propia (`components/touchpad`).
   * Detección del estado de los 6 botones capacitivos de la placa de expansión mediante la técnica de polling.
   * Modificación del estado del LED RGB (color, brillo, encendido/apagado) dependiendo del botón presionado.

2. **Conectividad WiFi:**
   * **Modo AP (Access Point):** El ESP32-S2 despliega su propia red WiFi, permitiendo conexiones directas de clientes externos.
   * **Modo STA (Station):** El dispositivo actúa como cliente, conectándose a una infraestructura de red WiFi existente en el laboratorio.

3. **Servidor Web y Control Remoto:**
   * Servidor HTTP embebido que aloja una interfaz web (HTML, CSS, JS) integrada directamente en el archivo binario mediante la directiva `EMBED_FILES`.
   * Comunicación bidireccional cliente-servidor mediante solicitudes asíncronas (`fetch()`).
   * API REST con endpoints `GET /led` y `POST /led` para consultar y modificar el estado del LED utilizando estructuras de datos JSON (procesadas mediante cJSON).

4. **Integración Completa:**
   * Consistencia de estado: Los cambios efectuados físicamente mediante el TouchPad se ven reflejados en la interfaz web, asegurando que ambas interfaces de control operen en armonía.

## Estructura del Repositorio
El repositorio contiene dos proyectos principales de ESP-IDF:
* `/Laboratorio_2a`: Implementación inicial enfocada únicamente en el control por TouchPad.
* `/Laboratorio_2b`: Proyecto integrador con la gestión de conectividad WiFi, el servidor HTTP y la interfaz web.
