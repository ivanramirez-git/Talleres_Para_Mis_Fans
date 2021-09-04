package com.company;

import java.net.URL;

public class Main {

    public static void main(String[] args) {
	// write your code here
        URL url = new URL("http://www.learnwebservices.com/services/hello?wsdl");
        HelloEndpointService service = new HelloEndpointService(url);
        HelloEndpoint port = service.getHelloEndpointPort();
        HelloRequest request = new HelloRequest();
        request.setName("John Doe");
        HelloResponse response = port.sayHello(request);
        System.out.println(response.getMessage());
    }
}
