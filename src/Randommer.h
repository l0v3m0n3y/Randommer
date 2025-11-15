#ifndef RANDOMMER_H
#define RANDOMMER_H

#include <cpprest/http_client.h>
#include <cpprest/json.h>
#include <pplx/pplx.h>
#include <iostream>
#include <string>
#include <map>

using namespace web;
using namespace web::http;
using namespace web::http::client;

class Randommer {
private:
    std::string api_base = "https://randommer.io";
    http_client_config client_config;
    
    http_request create_request(const std::string& path, method m, const std::string& body_data = "", const std::string& content_type = "") {
        http_request request(m);
        
        // Полный набор браузерных заголовков
        request.headers().add("Accept", "application/json");
        request.headers().add("Content-Type", "application/x-www-form-urlencoded; charset=UTF-8"); 
        request.headers().add("User-Agent", "Mozilla/5.0 (X11; Linux x86_64; rv:109.0) Gecko/20100101 Firefox/115.0");
        
        // Устанавливаем тело запроса, если передано
        if (!body_data.empty() && !content_type.empty()) {
            request.set_body(body_data, utility::conversions::to_string_t(content_type));
        }
        
        request.set_request_uri(utility::conversions::to_string_t(path));
        return request;
    }

public:
    Randommer() {
        client_config.set_validate_certificates(false);
    }

    pplx::task<json::value> prime_numbers(int interval) {
        
        http_client client(utility::conversions::to_string_t(api_base), client_config);
        std::string path = "/prime-numbers";
        auto request = create_request(path, methods::POST, "interval=" + std::to_string(interval) + "&X-Requested-With=XMLHttpRequest","application/x-www-form-urlencoded; charset=UTF-8");
        
        return client.request(request)
            .then([](http_response response) {
                if (response.status_code() == status_codes::OK) {
                    return response.extract_json();
                } else {
                    json::value error_obj;
                    error_obj[U("error")] = json::value::string(
                        U("HTTP Error: " + std::to_string(response.status_code())));
                    error_obj[U("success")] = json::value::boolean(false);
                    return pplx::task_from_result(error_obj);
                }
            })
            .then([](pplx::task<json::value> previousTask) {
                try {
                    return previousTask.get();
                } catch (const std::exception& e) {
                    json::value error_obj;
                    error_obj[U("error")] = json::value::string(
                        U("Exception: " + std::string(e.what())));
                    error_obj[U("success")] = json::value::boolean(false);
                    return error_obj;
                }
            });
    }

    pplx::task<json::value> routing_number_generator() {
        
        http_client client(utility::conversions::to_string_t(api_base), client_config);
        std::string path = "/routing-number-generator";
        auto request = create_request(path, methods::POST,"&X-Requested-With=XMLHttpRequest","application/x-www-form-urlencoded; charset=UTF-8");
        
        return client.request(request)
            .then([](http_response response) {
                if (response.status_code() == status_codes::OK) {
                    return response.extract_json();
                } else {
                    json::value error_obj;
                    error_obj[U("error")] = json::value::string(
                        U("HTTP Error: " + std::to_string(response.status_code())));
                    error_obj[U("success")] = json::value::boolean(false);
                    return pplx::task_from_result(error_obj);
                }
            })
            .then([](pplx::task<json::value> previousTask) {
                try {
                    return previousTask.get();
                } catch (const std::exception& e) {
                    json::value error_obj;
                    error_obj[U("error")] = json::value::string(
                        U("Exception: " + std::string(e.what())));
                    error_obj[U("success")] = json::value::boolean(false);
                    return error_obj;
                }
            });
    }

    pplx::task<json::value> username_generator(const std::string& culture,const std::string& firstname,const std::string& lastname) {
        
        http_client client(utility::conversions::to_string_t(api_base), client_config);
        std::string path = "/username-generator";
        auto request = create_request(path, methods::POST,"culture="+ utility::conversions::to_utf8string(web::uri::encode_data_string(utility::conversions::to_string_t(culture))) + "&firstname=" + utility::conversions::to_utf8string(web::uri::encode_data_string(utility::conversions::to_string_t(firstname))) + "&lastname=" + utility::conversions::to_utf8string(web::uri::encode_data_string(utility::conversions::to_string_t(lastname))) +"&X-Requested-With=XMLHttpRequest","application/x-www-form-urlencoded; charset=UTF-8");
        
        return client.request(request)
            .then([](http_response response) {
                if (response.status_code() == status_codes::OK) {
                    return response.extract_json();
                } else {
                    json::value error_obj;
                    error_obj[U("error")] = json::value::string(
                        U("HTTP Error: " + std::to_string(response.status_code())));
                    error_obj[U("success")] = json::value::boolean(false);
                    return pplx::task_from_result(error_obj);
                }
            })
            .then([](pplx::task<json::value> previousTask) {
                try {
                    return previousTask.get();
                } catch (const std::exception& e) {
                    json::value error_obj;
                    error_obj[U("error")] = json::value::string(
                        U("Exception: " + std::string(e.what())));
                    error_obj[U("success")] = json::value::boolean(false);
                    return error_obj;
                }
            });
    }

    pplx::task<json::value> vat_validator(const std::string& country,const std::string& vat) {
        
        http_client client(utility::conversions::to_string_t(api_base), client_config);
        std::string path = "/SocialNumber/VatValidator";
        auto request = create_request(path, methods::POST,"country="+ utility::conversions::to_utf8string(web::uri::encode_data_string(utility::conversions::to_string_t(country))) + "&vat=" + utility::conversions::to_utf8string(web::uri::encode_data_string(utility::conversions::to_string_t(vat))) +"&X-Requested-With=XMLHttpRequest","application/x-www-form-urlencoded; charset=UTF-8");
        
        return client.request(request)
            .then([](http_response response) {
                if (response.status_code() == status_codes::OK) {
                    return response.extract_json();
                } else {
                    json::value error_obj;
                    error_obj[U("error")] = json::value::string(
                        U("HTTP Error: " + std::to_string(response.status_code())));
                    error_obj[U("success")] = json::value::boolean(false);
                    return pplx::task_from_result(error_obj);
                }
            })
            .then([](pplx::task<json::value> previousTask) {
                try {
                    return previousTask.get();
                } catch (const std::exception& e) {
                    json::value error_obj;
                    error_obj[U("error")] = json::value::string(
                        U("Exception: " + std::string(e.what())));
                    error_obj[U("success")] = json::value::boolean(false);
                    return error_obj;
                }
            });
    }

    pplx::task<json::value> bitcoin_address_generator(const std::string& crypto_type) {
        
        http_client client(utility::conversions::to_string_t(api_base), client_config);
        std::string path = "/bitcoin-address-generator";
        auto request = create_request(path, methods::POST,"cryptoType="+ utility::conversions::to_utf8string(web::uri::encode_data_string(utility::conversions::to_string_t(crypto_type))) +"&X-Requested-With=XMLHttpRequest","application/x-www-form-urlencoded; charset=UTF-8");
        
        return client.request(request)
            .then([](http_response response) {
                if (response.status_code() == status_codes::OK) {
                    return response.extract_json();
                } else {
                    json::value error_obj;
                    error_obj[U("error")] = json::value::string(
                        U("HTTP Error: " + std::to_string(response.status_code())));
                    error_obj[U("success")] = json::value::boolean(false);
                    return pplx::task_from_result(error_obj);
                }
            })
            .then([](pplx::task<json::value> previousTask) {
                try {
                    return previousTask.get();
                } catch (const std::exception& e) {
                    json::value error_obj;
                    error_obj[U("error")] = json::value::string(
                        U("Exception: " + std::string(e.what())));
                    error_obj[U("success")] = json::value::boolean(false);
                    return error_obj;
                }
            });
    }

    pplx::task<json::value> fake_card_generate(const std::string& type) {
        
        http_client client(utility::conversions::to_string_t(api_base), client_config);
        std::string path = "/Card";
        auto request = create_request(path, methods::POST,"Type="+ utility::conversions::to_utf8string(web::uri::encode_data_string(utility::conversions::to_string_t(type))) +"&X-Requested-With=XMLHttpRequest","application/x-www-form-urlencoded; charset=UTF-8");
        
        return client.request(request)
            .then([](http_response response) {
                if (response.status_code() == status_codes::OK) {
                    return response.extract_json();
                } else {
                    json::value error_obj;
                    error_obj[U("error")] = json::value::string(
                        U("HTTP Error: " + std::to_string(response.status_code())));
                    error_obj[U("success")] = json::value::boolean(false);
                    return pplx::task_from_result(error_obj);
                }
            })
            .then([](pplx::task<json::value> previousTask) {
                try {
                    return previousTask.get();
                } catch (const std::exception& e) {
                    json::value error_obj;
                    error_obj[U("error")] = json::value::string(
                        U("Exception: " + std::string(e.what())));
                    error_obj[U("success")] = json::value::boolean(false);
                    return error_obj;
                }
            });
    }

    pplx::task<json::value> guid_generator(int quantity) {
        
        http_client client(utility::conversions::to_string_t(api_base), client_config);
        std::string path = "/guid-generator";
        auto request = create_request(path, methods::POST,"quantity=" + std::to_string(quantity) +"&X-Requested-With=XMLHttpRequest","application/x-www-form-urlencoded; charset=UTF-8");
        
        return client.request(request)
            .then([](http_response response) {
                if (response.status_code() == status_codes::OK) {
                    return response.extract_json();
                } else {
                    json::value error_obj;
                    error_obj[U("error")] = json::value::string(
                        U("HTTP Error: " + std::to_string(response.status_code())));
                    error_obj[U("success")] = json::value::boolean(false);
                    return pplx::task_from_result(error_obj);
                }
            })
            .then([](pplx::task<json::value> previousTask) {
                try {
                    return previousTask.get();
                } catch (const std::exception& e) {
                    json::value error_obj;
                    error_obj[U("error")] = json::value::string(
                        U("Exception: " + std::string(e.what())));
                    error_obj[U("success")] = json::value::boolean(false);
                    return error_obj;
                }
            });
    }

    pplx::task<json::value> random_mac_address(int number) {
        
        http_client client(utility::conversions::to_string_t(api_base), client_config);
        std::string path = "/random-mac-address";
        auto request = create_request(path, methods::POST,"number=" + std::to_string(number) +"&X-Requested-With=XMLHttpRequest","application/x-www-form-urlencoded; charset=UTF-8");
        
        return client.request(request)
            .then([](http_response response) {
                if (response.status_code() == status_codes::OK) {
                    return response.extract_json();
                } else {
                    json::value error_obj;
                    error_obj[U("error")] = json::value::string(
                        U("HTTP Error: " + std::to_string(response.status_code())));
                    error_obj[U("success")] = json::value::boolean(false);
                    return pplx::task_from_result(error_obj);
                }
            })
            .then([](pplx::task<json::value> previousTask) {
                try {
                    return previousTask.get();
                } catch (const std::exception& e) {
                    json::value error_obj;
                    error_obj[U("error")] = json::value::string(
                        U("Exception: " + std::string(e.what())));
                    error_obj[U("success")] = json::value::boolean(false);
                    return error_obj;
                }
            });
    }

    pplx::task<json::value> tiktok_username_generator(const std::string& firstname,const std::string& lastname) {
        
        http_client client(utility::conversions::to_string_t(api_base), client_config);
        std::string path = "/tiktok-name-generator";
        auto request = create_request(path, methods::POST,"firstname=" + utility::conversions::to_utf8string(web::uri::encode_data_string(utility::conversions::to_string_t(firstname))) + "&lastname=" + utility::conversions::to_utf8string(web::uri::encode_data_string(utility::conversions::to_string_t(lastname))) +"&X-Requested-With=XMLHttpRequest","application/x-www-form-urlencoded; charset=UTF-8");
        
        return client.request(request)
            .then([](http_response response) {
                if (response.status_code() == status_codes::OK) {
                    return response.extract_json();
                } else {
                    json::value error_obj;
                    error_obj[U("error")] = json::value::string(
                        U("HTTP Error: " + std::to_string(response.status_code())));
                    error_obj[U("success")] = json::value::boolean(false);
                    return pplx::task_from_result(error_obj);
                }
            })
            .then([](pplx::task<json::value> previousTask) {
                try {
                    return previousTask.get();
                } catch (const std::exception& e) {
                    json::value error_obj;
                    error_obj[U("error")] = json::value::string(
                        U("Exception: " + std::string(e.what())));
                    error_obj[U("success")] = json::value::boolean(false);
                    return error_obj;
                }
            });
    }

    pplx::task<json::value> name_generator(const std::string& type,int number) {
        
        http_client client(utility::conversions::to_string_t(api_base), client_config);
        std::string path = "/Name";
        auto request = create_request(path, methods::POST,"type=" + utility::conversions::to_utf8string(web::uri::encode_data_string(utility::conversions::to_string_t(type))) + "&number=" + std::to_string(number) +"&X-Requested-With=XMLHttpRequest","application/x-www-form-urlencoded; charset=UTF-8");
        
        return client.request(request)
            .then([](http_response response) {
                if (response.status_code() == status_codes::OK) {
                    return response.extract_json();
                } else {
                    json::value error_obj;
                    error_obj[U("error")] = json::value::string(
                        U("HTTP Error: " + std::to_string(response.status_code())));
                    error_obj[U("success")] = json::value::boolean(false);
                    return pplx::task_from_result(error_obj);
                }
            })
            .then([](pplx::task<json::value> previousTask) {
                try {
                    return previousTask.get();
                } catch (const std::exception& e) {
                    json::value error_obj;
                    error_obj[U("error")] = json::value::string(
                        U("Exception: " + std::string(e.what())));
                    error_obj[U("success")] = json::value::boolean(false);
                    return error_obj;
                }
            });
    }

    pplx::task<json::value> baby_name_generator(const std::string& culture,int gender) {
        
        http_client client(utility::conversions::to_string_t(api_base), client_config);
        std::string path = "/Name";
        auto request = create_request(path, methods::POST,"culture=" + utility::conversions::to_utf8string(web::uri::encode_data_string(utility::conversions::to_string_t(culture))) + "&gender=" + std::to_string(gender) +"&X-Requested-With=XMLHttpRequest","application/x-www-form-urlencoded; charset=UTF-8");
        
        return client.request(request)
            .then([](http_response response) {
                if (response.status_code() == status_codes::OK) {
                    return response.extract_json();
                } else {
                    json::value error_obj;
                    error_obj[U("error")] = json::value::string(
                        U("HTTP Error: " + std::to_string(response.status_code())));
                    error_obj[U("success")] = json::value::boolean(false);
                    return pplx::task_from_result(error_obj);
                }
            })
            .then([](pplx::task<json::value> previousTask) {
                try {
                    return previousTask.get();
                } catch (const std::exception& e) {
                    json::value error_obj;
                    error_obj[U("error")] = json::value::string(
                        U("Exception: " + std::string(e.what())));
                    error_obj[U("success")] = json::value::boolean(false);
                    return error_obj;
                }
            });
    }

    pplx::task<json::value> brand_name_generator(const std::string& start_word,int gender) {
        
        http_client client(utility::conversions::to_string_t(api_base), client_config);
        std::string path = "/brand-name-generator";
        auto request = create_request(path, methods::POST,"StartingWords=" + utility::conversions::to_utf8string(web::uri::encode_data_string(utility::conversions::to_string_t(start_word))) +"&X-Requested-With=XMLHttpRequest","application/x-www-form-urlencoded; charset=UTF-8");
        
        return client.request(request)
            .then([](http_response response) {
                if (response.status_code() == status_codes::OK) {
                    return response.extract_json();
                } else {
                    json::value error_obj;
                    error_obj[U("error")] = json::value::string(
                        U("HTTP Error: " + std::to_string(response.status_code())));
                    error_obj[U("success")] = json::value::boolean(false);
                    return pplx::task_from_result(error_obj);
                }
            })
            .then([](pplx::task<json::value> previousTask) {
                try {
                    return previousTask.get();
                } catch (const std::exception& e) {
                    json::value error_obj;
                    error_obj[U("error")] = json::value::string(
                        U("Exception: " + std::string(e.what())));
                    error_obj[U("success")] = json::value::boolean(false);
                    return error_obj;
                }
            });
    }

    pplx::task<json::value> business_name_generator(const std::string& culture,int number) {
        
        http_client client(utility::conversions::to_string_t(api_base), client_config);
        std::string path = "/random-business-names";
        auto request = create_request(path, methods::POST,"number=" + std::to_string(number) + "&culture=" + utility::conversions::to_utf8string(web::uri::encode_data_string(utility::conversions::to_string_t(culture))) +"&X-Requested-With=XMLHttpRequest","application/x-www-form-urlencoded; charset=UTF-8");
        
        return client.request(request)
            .then([](http_response response) {
                if (response.status_code() == status_codes::OK) {
                    return response.extract_json();
                } else {
                    json::value error_obj;
                    error_obj[U("error")] = json::value::string(
                        U("HTTP Error: " + std::to_string(response.status_code())));
                    error_obj[U("success")] = json::value::boolean(false);
                    return pplx::task_from_result(error_obj);
                }
            })
            .then([](pplx::task<json::value> previousTask) {
                try {
                    return previousTask.get();
                } catch (const std::exception& e) {
                    json::value error_obj;
                    error_obj[U("error")] = json::value::string(
                        U("Exception: " + std::string(e.what())));
                    error_obj[U("success")] = json::value::boolean(false);
                    return error_obj;
                }
            });
    }

    pplx::task<json::value> name_picker(const std::string& names,int count) {
        
        http_client client(utility::conversions::to_string_t(api_base), client_config);
        std::string path = "/random-business-names";
        auto request = create_request(path, methods::POST,"names=" + utility::conversions::to_utf8string(web::uri::encode_data_string(utility::conversions::to_string_t(names))) + "&count=" + std::to_string(count) +"&X-Requested-With=XMLHttpRequest","application/x-www-form-urlencoded; charset=UTF-8");
        
        return client.request(request)
            .then([](http_response response) {
                if (response.status_code() == status_codes::OK) {
                    return response.extract_json();
                } else {
                    json::value error_obj;
                    error_obj[U("error")] = json::value::string(
                        U("HTTP Error: " + std::to_string(response.status_code())));
                    error_obj[U("success")] = json::value::boolean(false);
                    return pplx::task_from_result(error_obj);
                }
            })
            .then([](pplx::task<json::value> previousTask) {
                try {
                    return previousTask.get();
                } catch (const std::exception& e) {
                    json::value error_obj;
                    error_obj[U("error")] = json::value::string(
                        U("Exception: " + std::string(e.what())));
                    error_obj[U("success")] = json::value::boolean(false);
                    return error_obj;
                }
            });
    }

    pplx::task<json::value> pet_names(const std::string& animal,int number) {
        
        http_client client(utility::conversions::to_string_t(api_base), client_config);
        std::string path = "/random-business-names";
        auto request = create_request(path, methods::POST,"animal=" + utility::conversions::to_utf8string(web::uri::encode_data_string(utility::conversions::to_string_t(animal))) + "&number=" + std::to_string(number) +"&X-Requested-With=XMLHttpRequest","application/x-www-form-urlencoded; charset=UTF-8");
        
        return client.request(request)
            .then([](http_response response) {
                if (response.status_code() == status_codes::OK) {
                    return response.extract_json();
                } else {
                    json::value error_obj;
                    error_obj[U("error")] = json::value::string(
                        U("HTTP Error: " + std::to_string(response.status_code())));
                    error_obj[U("success")] = json::value::boolean(false);
                    return pplx::task_from_result(error_obj);
                }
            })
            .then([](pplx::task<json::value> previousTask) {
                try {
                    return previousTask.get();
                } catch (const std::exception& e) {
                    json::value error_obj;
                    error_obj[U("error")] = json::value::string(
                        U("Exception: " + std::string(e.what())));
                    error_obj[U("success")] = json::value::boolean(false);
                    return error_obj;
                }
            });
    }

    pplx::task<json::value> imei_generator(int id) {
        
        http_client client(utility::conversions::to_string_t(api_base), client_config);
        std::string path = "/imei-generator";
        auto request = create_request(path, methods::POST,"id=" + std::to_string(id) +"&X-Requested-With=XMLHttpRequest","application/x-www-form-urlencoded; charset=UTF-8");
        
        return client.request(request)
            .then([](http_response response) {
                if (response.status_code() == status_codes::OK) {
                    return response.extract_json();
                } else {
                    json::value error_obj;
                    error_obj[U("error")] = json::value::string(
                        U("HTTP Error: " + std::to_string(response.status_code())));
                    error_obj[U("success")] = json::value::boolean(false);
                    return pplx::task_from_result(error_obj);
                }
            })
            .then([](pplx::task<json::value> previousTask) {
                try {
                    return previousTask.get();
                } catch (const std::exception& e) {
                    json::value error_obj;
                    error_obj[U("error")] = json::value::string(
                        U("Exception: " + std::string(e.what())));
                    error_obj[U("success")] = json::value::boolean(false);
                    return error_obj;
                }
            });
    }

    pplx::task<json::value> phone_id_address(const std::string& deviceIdType) {
        
        http_client client(utility::conversions::to_string_t(api_base), client_config);
        std::string path = "/phone-id-address";
        auto request = create_request(path, methods::POST,"deviceIdType=" + utility::conversions::to_utf8string(web::uri::encode_data_string(utility::conversions::to_string_t(deviceIdType))) +"&X-Requested-With=XMLHttpRequest","application/x-www-form-urlencoded; charset=UTF-8");
        
        return client.request(request)
            .then([](http_response response) {
                if (response.status_code() == status_codes::OK) {
                    return response.extract_json();
                } else {
                    json::value error_obj;
                    error_obj[U("error")] = json::value::string(
                        U("HTTP Error: " + std::to_string(response.status_code())));
                    error_obj[U("success")] = json::value::boolean(false);
                    return pplx::task_from_result(error_obj);
                }
            })
            .then([](pplx::task<json::value> previousTask) {
                try {
                    return previousTask.get();
                } catch (const std::exception& e) {
                    json::value error_obj;
                    error_obj[U("error")] = json::value::string(
                        U("Exception: " + std::string(e.what())));
                    error_obj[U("success")] = json::value::boolean(false);
                    return error_obj;
                }
            });
    }

    pplx::task<json::value>  generate_telephones(int number,const std::string& twoLettersCode) {
        
        http_client client(utility::conversions::to_string_t(api_base), client_config);
        std::string path = "/free-valid-bulk-telephones-generator";
        auto request = create_request(path, methods::POST,"number=" + std::to_string(number) + "&twoLettersCode=" + utility::conversions::to_utf8string(web::uri::encode_data_string(utility::conversions::to_string_t(twoLettersCode))) +"&X-Requested-With=XMLHttpRequest","application/x-www-form-urlencoded; charset=UTF-8");
        
        return client.request(request)
            .then([](http_response response) {
                if (response.status_code() == status_codes::OK) {
                    return response.extract_json();
                } else {
                    json::value error_obj;
                    error_obj[U("error")] = json::value::string(
                        U("HTTP Error: " + std::to_string(response.status_code())));
                    error_obj[U("success")] = json::value::boolean(false);
                    return pplx::task_from_result(error_obj);
                }
            })
            .then([](pplx::task<json::value> previousTask) {
                try {
                    return previousTask.get();
                } catch (const std::exception& e) {
                    json::value error_obj;
                    error_obj[U("error")] = json::value::string(
                        U("Exception: " + std::string(e.what())));
                    error_obj[U("success")] = json::value::boolean(false);
                    return error_obj;
                }
            });
    }

    pplx::task<json::value>  time_between_dates(const std::string& starttime,const std::string& endtime) {
        
        http_client client(utility::conversions::to_string_t(api_base), client_config);
        std::string path = "/time-between-dates";
        auto request = create_request(path, methods::POST,"startTime=" + utility::conversions::to_utf8string(web::uri::encode_data_string(utility::conversions::to_string_t(starttime))) + "&endtime=" + utility::conversions::to_utf8string(web::uri::encode_data_string(utility::conversions::to_string_t(endtime))) +"&X-Requested-With=XMLHttpRequest","application/x-www-form-urlencoded; charset=UTF-8");
        
        return client.request(request)
            .then([](http_response response) {
                if (response.status_code() == status_codes::OK) {
                    return response.extract_json();
                } else {
                    json::value error_obj;
                    error_obj[U("error")] = json::value::string(
                        U("HTTP Error: " + std::to_string(response.status_code())));
                    error_obj[U("success")] = json::value::boolean(false);
                    return pplx::task_from_result(error_obj);
                }
            })
            .then([](pplx::task<json::value> previousTask) {
                try {
                    return previousTask.get();
                } catch (const std::exception& e) {
                    json::value error_obj;
                    error_obj[U("error")] = json::value::string(
                        U("Exception: " + std::string(e.what())));
                    error_obj[U("success")] = json::value::boolean(false);
                    return error_obj;
                }
            });
    }

    pplx::task<json::value>  random_address(int number,const std::string& culture) {
        
        http_client client(utility::conversions::to_string_t(api_base), client_config);
        std::string path = "/random-address";
        auto request = create_request(path, methods::POST,"number=" + std::to_string(number) + "&culture=" + utility::conversions::to_utf8string(web::uri::encode_data_string(utility::conversions::to_string_t(culture))) +"&X-Requested-With=XMLHttpRequest","application/x-www-form-urlencoded; charset=UTF-8");
        
        return client.request(request)
            .then([](http_response response) {
                if (response.status_code() == status_codes::OK) {
                    return response.extract_json();
                } else {
                    json::value error_obj;
                    error_obj[U("error")] = json::value::string(
                        U("HTTP Error: " + std::to_string(response.status_code())));
                    error_obj[U("success")] = json::value::boolean(false);
                    return pplx::task_from_result(error_obj);
                }
            })
            .then([](pplx::task<json::value> previousTask) {
                try {
                    return previousTask.get();
                } catch (const std::exception& e) {
                    json::value error_obj;
                    error_obj[U("error")] = json::value::string(
                        U("Exception: " + std::string(e.what())));
                    error_obj[U("success")] = json::value::boolean(false);
                    return error_obj;
                }
            });
    }


    pplx::task<json::value>  ssn_validator(const std::string& country,const std::string& ssn) {
        
        http_client client(utility::conversions::to_string_t(api_base), client_config);
        std::string path = "/SocialNumber/SsnValidator";
        auto request = create_request(path, methods::POST,"country=" + utility::conversions::to_utf8string(web::uri::encode_data_string(utility::conversions::to_string_t(country))) + "&ssn=" + utility::conversions::to_utf8string(web::uri::encode_data_string(utility::conversions::to_string_t(ssn))) +"&X-Requested-With=XMLHttpRequest","application/x-www-form-urlencoded; charset=UTF-8");
        
        return client.request(request)
            .then([](http_response response) {
                if (response.status_code() == status_codes::OK) {
                    return response.extract_json();
                } else {
                    json::value error_obj;
                    error_obj[U("error")] = json::value::string(
                        U("HTTP Error: " + std::to_string(response.status_code())));
                    error_obj[U("success")] = json::value::boolean(false);
                    return pplx::task_from_result(error_obj);
                }
            })
            .then([](pplx::task<json::value> previousTask) {
                try {
                    return previousTask.get();
                } catch (const std::exception& e) {
                    json::value error_obj;
                    error_obj[U("error")] = json::value::string(
                        U("Exception: " + std::string(e.what())));
                    error_obj[U("success")] = json::value::boolean(false);
                    return error_obj;
                }
            });
    }


    pplx::task<json::value>  generate_review(const std::string& product,int number) {
        
        http_client client(utility::conversions::to_string_t(api_base), client_config);
        std::string path = "/Text/Review";
        auto request = create_request(path, methods::POST,"product=" + utility::conversions::to_utf8string(web::uri::encode_data_string(utility::conversions::to_string_t(product))) + "&number=" + std::to_string(number) +"&X-Requested-With=XMLHttpRequest","application/x-www-form-urlencoded; charset=UTF-8");
        
        return client.request(request)
            .then([](http_response response) {
                if (response.status_code() == status_codes::OK) {
                    return response.extract_json();
                } else {
                    json::value error_obj;
                    error_obj[U("error")] = json::value::string(
                        U("HTTP Error: " + std::to_string(response.status_code())));
                    error_obj[U("success")] = json::value::boolean(false);
                    return pplx::task_from_result(error_obj);
                }
            })
            .then([](pplx::task<json::value> previousTask) {
                try {
                    return previousTask.get();
                } catch (const std::exception& e) {
                    json::value error_obj;
                    error_obj[U("error")] = json::value::string(
                        U("Exception: " + std::string(e.what())));
                    error_obj[U("success")] = json::value::boolean(false);
                    return error_obj;
                }
            });
    }


    pplx::task<json::value>  word_generator(int quantity,int wordType) {
        
        http_client client(utility::conversions::to_string_t(api_base), client_config);
        std::string path = "/word-generator";
        auto request = create_request(path, methods::POST,"quantity=" + std::to_string(quantity) + "&wordType=" + std::to_string(wordType) +"&X-Requested-With=XMLHttpRequest","application/x-www-form-urlencoded; charset=UTF-8");
        
        return client.request(request)
            .then([](http_response response) {
                if (response.status_code() == status_codes::OK) {
                    return response.extract_json();
                } else {
                    json::value error_obj;
                    error_obj[U("error")] = json::value::string(
                        U("HTTP Error: " + std::to_string(response.status_code())));
                    error_obj[U("success")] = json::value::boolean(false);
                    return pplx::task_from_result(error_obj);
                }
            })
            .then([](pplx::task<json::value> previousTask) {
                try {
                    return previousTask.get();
                } catch (const std::exception& e) {
                    json::value error_obj;
                    error_obj[U("error")] = json::value::string(
                        U("Exception: " + std::string(e.what())));
                    error_obj[U("success")] = json::value::boolean(false);
                    return error_obj;
                }
            });
    }


    pplx::task<json::value>  random_bible_verse(int quantity) {
        
        http_client client(utility::conversions::to_string_t(api_base), client_config);
        std::string path = "/random-bible-verse";
        auto request = create_request(path, methods::POST,"quantity=" + std::to_string(quantity) +"&X-Requested-With=XMLHttpRequest","application/x-www-form-urlencoded; charset=UTF-8");
        
        return client.request(request)
            .then([](http_response response) {
                if (response.status_code() == status_codes::OK) {
                    return response.extract_json();
                } else {
                    json::value error_obj;
                    error_obj[U("error")] = json::value::string(
                        U("HTTP Error: " + std::to_string(response.status_code())));
                    error_obj[U("success")] = json::value::boolean(false);
                    return pplx::task_from_result(error_obj);
                }
            })
            .then([](pplx::task<json::value> previousTask) {
                try {
                    return previousTask.get();
                } catch (const std::exception& e) {
                    json::value error_obj;
                    error_obj[U("error")] = json::value::string(
                        U("Exception: " + std::string(e.what())));
                    error_obj[U("success")] = json::value::boolean(false);
                    return error_obj;
                }
            });
    }


    pplx::task<json::value>  fibonacci_numbers(int limit) {
        
        http_client client(utility::conversions::to_string_t(api_base), client_config);
        std::string path = "/fibonacci-numbers";
        auto request = create_request(path, methods::POST,"limit=" + std::to_string(limit) +"&X-Requested-With=XMLHttpRequest","application/x-www-form-urlencoded; charset=UTF-8");
        
        return client.request(request)
            .then([](http_response response) {
                if (response.status_code() == status_codes::OK) {
                    return response.extract_json();
                } else {
                    json::value error_obj;
                    error_obj[U("error")] = json::value::string(
                        U("HTTP Error: " + std::to_string(response.status_code())));
                    error_obj[U("success")] = json::value::boolean(false);
                    return pplx::task_from_result(error_obj);
                }
            })
            .then([](pplx::task<json::value> previousTask) {
                try {
                    return previousTask.get();
                } catch (const std::exception& e) {
                    json::value error_obj;
                    error_obj[U("error")] = json::value::string(
                        U("Exception: " + std::string(e.what())));
                    error_obj[U("success")] = json::value::boolean(false);
                    return error_obj;
                }
            });
    }


    pplx::task<json::value>  bitwise_calculator(const std::string& dataType,int number1,int number2,const std::string& operation) {
        
        http_client client(utility::conversions::to_string_t(api_base), client_config);
        std::string path = "/bitwise-calculator";
        auto request = create_request(path, methods::POST,"dataType=" + utility::conversions::to_utf8string(web::uri::encode_data_string(utility::conversions::to_string_t(dataType))) + "&number1=" + std::to_string(number1) + "&number2=" + std::to_string(number2) + "&operation=" + utility::conversions::to_utf8string(web::uri::encode_data_string(utility::conversions::to_string_t(operation))) +"&X-Requested-With=XMLHttpRequest","application/x-www-form-urlencoded; charset=UTF-8");
        
        return client.request(request)
            .then([](http_response response) {
                if (response.status_code() == status_codes::OK) {
                    return response.extract_json();
                } else {
                    json::value error_obj;
                    error_obj[U("error")] = json::value::string(
                        U("HTTP Error: " + std::to_string(response.status_code())));
                    error_obj[U("success")] = json::value::boolean(false);
                    return pplx::task_from_result(error_obj);
                }
            })
            .then([](pplx::task<json::value> previousTask) {
                try {
                    return previousTask.get();
                } catch (const std::exception& e) {
                    json::value error_obj;
                    error_obj[U("error")] = json::value::string(
                        U("Exception: " + std::string(e.what())));
                    error_obj[U("success")] = json::value::boolean(false);
                    return error_obj;
                }
            });
    }
};

#endif
