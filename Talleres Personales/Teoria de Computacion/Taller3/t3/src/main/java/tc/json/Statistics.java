
package tc.json;

import java.util.HashMap;
import java.util.Map;
import javax.annotation.processing.Generated;
import com.fasterxml.jackson.annotation.JsonAnyGetter;
import com.fasterxml.jackson.annotation.JsonAnySetter;
import com.fasterxml.jackson.annotation.JsonIgnore;
import com.fasterxml.jackson.annotation.JsonInclude;
import com.fasterxml.jackson.annotation.JsonProperty;
import com.fasterxml.jackson.annotation.JsonPropertyOrder;

@JsonInclude(JsonInclude.Include.NON_NULL)
@JsonPropertyOrder({
    "# of Delays",
    "Carriers",
    "Flights",
    "Minutes Delayed"
})
@Generated("jsonschema2pojo")
public class Statistics {

    @JsonProperty("# of Delays")
    private OfDelays ofDelays;
    @JsonProperty("Carriers")
    private Carriers carriers;
    @JsonProperty("Flights")
    private Flights flights;
    @JsonProperty("Minutes Delayed")
    private MinutesDelayed minutesDelayed;
    @JsonIgnore
    private Map<String, Object> additionalProperties = new HashMap<String, Object>();

    @JsonProperty("# of Delays")
    public OfDelays getOfDelays() {
        return ofDelays;
    }

    @JsonProperty("# of Delays")
    public void setOfDelays(OfDelays ofDelays) {
        this.ofDelays = ofDelays;
    }

    @JsonProperty("Carriers")
    public Carriers getCarriers() {
        return carriers;
    }

    @JsonProperty("Carriers")
    public void setCarriers(Carriers carriers) {
        this.carriers = carriers;
    }

    @JsonProperty("Flights")
    public Flights getFlights() {
        return flights;
    }

    @JsonProperty("Flights")
    public void setFlights(Flights flights) {
        this.flights = flights;
    }

    @JsonProperty("Minutes Delayed")
    public MinutesDelayed getMinutesDelayed() {
        return minutesDelayed;
    }

    @JsonProperty("Minutes Delayed")
    public void setMinutesDelayed(MinutesDelayed minutesDelayed) {
        this.minutesDelayed = minutesDelayed;
    }

    @JsonAnyGetter
    public Map<String, Object> getAdditionalProperties() {
        return this.additionalProperties;
    }

    @JsonAnySetter
    public void setAdditionalProperty(String name, Object value) {
        this.additionalProperties.put(name, value);
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(Statistics.class.getName()).append('@').append(Integer.toHexString(System.identityHashCode(this))).append('[');
        sb.append("ofDelays");
        sb.append('=');
        sb.append(((this.ofDelays == null)?"<null>":this.ofDelays));
        sb.append(',');
        sb.append("carriers");
        sb.append('=');
        sb.append(((this.carriers == null)?"<null>":this.carriers));
        sb.append(',');
        sb.append("flights");
        sb.append('=');
        sb.append(((this.flights == null)?"<null>":this.flights));
        sb.append(',');
        sb.append("minutesDelayed");
        sb.append('=');
        sb.append(((this.minutesDelayed == null)?"<null>":this.minutesDelayed));
        sb.append(',');
        sb.append("additionalProperties");
        sb.append('=');
        sb.append(((this.additionalProperties == null)?"<null>":this.additionalProperties));
        sb.append(',');
        if (sb.charAt((sb.length()- 1)) == ',') {
            sb.setCharAt((sb.length()- 1), ']');
        } else {
            sb.append(']');
        }
        return sb.toString();
    }

    @Override
    public int hashCode() {
        int result = 1;
        result = ((result* 31)+((this.carriers == null)? 0 :this.carriers.hashCode()));
        result = ((result* 31)+((this.additionalProperties == null)? 0 :this.additionalProperties.hashCode()));
        result = ((result* 31)+((this.flights == null)? 0 :this.flights.hashCode()));
        result = ((result* 31)+((this.minutesDelayed == null)? 0 :this.minutesDelayed.hashCode()));
        result = ((result* 31)+((this.ofDelays == null)? 0 :this.ofDelays.hashCode()));
        return result;
    }

    @Override
    public boolean equals(Object other) {
        if (other == this) {
            return true;
        }
        if ((other instanceof Statistics) == false) {
            return false;
        }
        Statistics rhs = ((Statistics) other);
        return ((((((this.carriers == rhs.carriers)||((this.carriers!= null)&&this.carriers.equals(rhs.carriers)))&&((this.additionalProperties == rhs.additionalProperties)||((this.additionalProperties!= null)&&this.additionalProperties.equals(rhs.additionalProperties))))&&((this.flights == rhs.flights)||((this.flights!= null)&&this.flights.equals(rhs.flights))))&&((this.minutesDelayed == rhs.minutesDelayed)||((this.minutesDelayed!= null)&&this.minutesDelayed.equals(rhs.minutesDelayed))))&&((this.ofDelays == rhs.ofDelays)||((this.ofDelays!= null)&&this.ofDelays.equals(rhs.ofDelays))));
    }

}
