idf_component_register(SRCS "main.c" "softap_sta.c"
                    PRIV_REQUIRES esp_wifi nvs_flash esp_http_server
                    INCLUDE_DIRS ".")
