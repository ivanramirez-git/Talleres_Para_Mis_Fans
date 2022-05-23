package tc;

import java.io.FileReader;

import com.fasterxml.jackson.databind.ObjectMapper;

import io.reactivex.rxjava3.core.Observable;
import tc.json.AirportStat;

public class Datos {


    public static Observable<AirportStat> getObservable() {
        AirportStat[] data;
        try {
            data = new ObjectMapper().readValue(new FileReader("json/airportStats.json"),
                    AirportStat[].class);
            return Observable.fromArray(data);
        } catch (Exception e) {
            e.printStackTrace();
            return null;
        }

    }

}
