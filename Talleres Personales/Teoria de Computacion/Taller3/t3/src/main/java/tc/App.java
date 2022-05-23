package tc;

import java.io.FileNotFoundException;

import io.reactivex.rxjava3.core.Observable;

/**
 * Implemente las siguientes funciones
 */
public class App {

    public static void main(String[] args) throws FileNotFoundException {
        Datos.getObservable().subscribe(a -> System.out.println(a.getAirport().getName())); // Imprime nombres de los
                                                                                            // aeropuertos

        totalCancelled("IAD", 6).subscribe(System.out::println); // Debe imprimir 2650
        airportCodes("Atlantic Coast Airlines").subscribe(System.out::println); // Debe imprimir 'BOS', 'CLT', 'DCA',
                                                                                // 'DTW', 'EWR', 'IAD', 'JFK', 'LGA',
                                                                                // 'MDW', 'ORD', 'PHL', 'ATL', 'BWI'
    }

    /**
     * Problema 1 (40%).
     * Returna el total de vuelos cancelados en el aeropuerto indicado por
     * `airportCode` en el mes indicado en el parámetro `month`
     * return Observable.just(0);
     */
    public static Observable<Integer> totalCancelled(String airportCode, Integer month) {
        // return Datos.getObservable().filter(a -> a.getAirport().getCode().equals(airportCode))
        //         .filter(a -> a.getMonth() == month).map(a -> a.getCancelled());
        // return Observable.just(0); // TODO Completar
        return Datos.getObservable().filter(a -> a.getAirport().getCode().equals(airportCode))
                .filter(a -> a.getMonth() == month).map(a -> a.getCancelled());
    }

    /**
     * Problema 2 (60%).
     * retorna los códigos de los aeropuertos cuyo listado de transportistas
     * (Carriers) incluye al indicado en el parámetro 'carrierName'
     * 
     */
    public static Observable<String> airportCodes(String carrierName) {
        // return Observable.just("Nada"); // TODO Completar
        return Datos.getObservable().filter(a -> a.getCarriers().contains(carrierName))
                .map(a -> a.getAirport().getCode());
    }

}
