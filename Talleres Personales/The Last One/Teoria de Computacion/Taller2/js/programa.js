require('./datos.js')
/*
datos = [
    {
        "Airport": {
            "Code": "ATL",
            "Name": "Atlanta, GA: Hartsfield-Jackson Atlanta International"
        },
        "Time": {
            "Label": "2003/06",
            "Month": 6,
            "Month Name": "June",
            "Year": 2003
        },
        "Statistics": {
            "# of Delays": {
                "Carrier": 1009,
                "Late Aircraft": 1275,
                "National Aviation System": 3217,
                "Security": 17,
                "Weather": 328
            },
            "Carriers": {
                "Names": "American Airlines Inc.,JetBlue Airways,Continental Air Lines Inc.,Delta Air Lines Inc.,Atlantic Southeast Airlines,AirTran Airways Corporation,America West Airlines Inc.,Northwest Airlines Inc.,ExpressJet Airlines Inc.,United Air Lines Inc.,US Airways Inc.",
                "Total": 11
            },
            "Flights": {
                "Cancelled": 216,
                "Delayed": 5843,
                "Diverted": 27,
                "On Time": 23974,
                "Total": 30060
            },
            "Minutes Delayed": {
                "Carrier": 61606,
                "Late Aircraft": 68335,
                "National Aviation System": 118831,
                "Security": 518,
                "Total": 268764,
                "Weather": 19474
            }
        }
    }
]
*/

// Problema 1 (20%). Implemente la siguiente función
function totalCancelled(airlines, airportCode, month) {

  // Returna el total de vuelos cancelados en el aeropuerto indicado por `airportCode` en el mes indicado en el parámetro `month`
  return airlines.reduce((total, airline) => {
    if (airline.Airport.Code === airportCode && airline.Time.Month === month) {
      return total + airline.Statistics.Flights.Cancelled
    } else {
      return total
    }
  }
    , 0)
}

// Problema 2 (30%). Implemente la siguiente función
function airportCodes(airlines, carrierName) {

  // Retorna los códigos de los aeropuertos cuyo listado de transportistas (Carriers) incluye al indicado en el parámetro 'carrierName'
  return airlines.reduce((codes, airline) => {
    if (airline.Statistics.Carriers.Names.includes(carrierName)) {
      codes.push(airline.Airport.Code)
    }
    return codes
  }
    , []).filter((code, index, codes) => codes.indexOf(code) === index)
}

console.log(totalCancelled(datos, "IAD", 6)) // Debe retornar 2650
console.log(airportCodes(datos, "Atlantic Coast Airlines")) // Debe retornar   'BOS', 'CLT', 'DCA', 'DTW', 'EWR', 'IAD', 'JFK', 'LGA', 'MDW', 'ORD', 'PHL', 'ATL', 'BWI'
