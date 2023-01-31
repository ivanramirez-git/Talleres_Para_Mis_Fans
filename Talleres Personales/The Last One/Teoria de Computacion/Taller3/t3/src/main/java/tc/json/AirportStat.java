
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
    "Airport",
    "Time",
    "Statistics"
})
@Generated("jsonschema2pojo")
public class AirportStat {

    @JsonProperty("Airport")
    private Airport airport;
    @JsonProperty("Time")
    private Time time;
    @JsonProperty("Statistics")
    private Statistics statistics;
    @JsonIgnore
    private Map<String, Object> additionalProperties = new HashMap<String, Object>();

    @JsonProperty("Airport")
    public Airport getAirport() {
        return airport;
    }

    @JsonProperty("Airport")
    public void setAirport(Airport airport) {
        this.airport = airport;
    }

    @JsonProperty("Time")
    public Time getTime() {
        return time;
    }

    @JsonProperty("Time")
    public void setTime(Time time) {
        this.time = time;
    }

    @JsonProperty("Statistics")
    public Statistics getStatistics() {
        return statistics;
    }

    @JsonProperty("Statistics")
    public void setStatistics(Statistics statistics) {
        this.statistics = statistics;
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
        sb.append(AirportStat.class.getName()).append('@').append(Integer.toHexString(System.identityHashCode(this))).append('[');
        sb.append("airport");
        sb.append('=');
        sb.append(((this.airport == null)?"<null>":this.airport));
        sb.append(',');
        sb.append("time");
        sb.append('=');
        sb.append(((this.time == null)?"<null>":this.time));
        sb.append(',');
        sb.append("statistics");
        sb.append('=');
        sb.append(((this.statistics == null)?"<null>":this.statistics));
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
        result = ((result* 31)+((this.time == null)? 0 :this.time.hashCode()));
        result = ((result* 31)+((this.additionalProperties == null)? 0 :this.additionalProperties.hashCode()));
        result = ((result* 31)+((this.airport == null)? 0 :this.airport.hashCode()));
        result = ((result* 31)+((this.statistics == null)? 0 :this.statistics.hashCode()));
        return result;
    }

    @Override
    public boolean equals(Object other) {
        if (other == this) {
            return true;
        }
        if ((other instanceof AirportStat) == false) {
            return false;
        }
        AirportStat rhs = ((AirportStat) other);
        return (((((this.time == rhs.time)||((this.time!= null)&&this.time.equals(rhs.time)))&&((this.additionalProperties == rhs.additionalProperties)||((this.additionalProperties!= null)&&this.additionalProperties.equals(rhs.additionalProperties))))&&((this.airport == rhs.airport)||((this.airport!= null)&&this.airport.equals(rhs.airport))))&&((this.statistics == rhs.statistics)||((this.statistics!= null)&&this.statistics.equals(rhs.statistics))));
    }

}
