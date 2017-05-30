#include <iostream>
#include <string>
#include "SFML\Network\Http.hpp"
#include "SFML\Network.hpp"
#include "rapidjson.h"
#include "reader.h"
#include "document.h"
//#include "json.hpp"

void main(){
	rapidjson::Reader reader;
	rapidjson::Document document;
	sf::Http http;
	http.setHost("http://query.yahooapis.com");
	sf::Http::Request conection;
	conection.setMethod(sf::Http::Request::Post);
	conection.setUri("/v1/public/yql?q=select%20item.condition%20from%20weather.forecast%20where%20woeid%20%3D%20468739&format=json&env=store%3A%2F%2Fdatatables.org%2Falltableswithkeys");
	conection.setHttpVersion(1, 1);
	sf::Http::Response response = http.sendRequest(conection);
	std::cout << "status: " << response.getStatus() << std::endl;
	std::cout << "HTTP version: " << response.getMajorHttpVersion() << "." << response.getMinorHttpVersion() << std::endl;
	std::cout << "body: " << response.getBody() << std::endl;
	//nlohmann::json data = nlohmann::json::parse(response.getBody().c_str());
	//std::cout << data["query"]["results"]["channel"]["item"]["condition"]["text"];

	//printf("text: = %s\n", document["text:"].GetString());
	std::cin.get();
}