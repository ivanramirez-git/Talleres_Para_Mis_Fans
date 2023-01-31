
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
    "Carrier",
    "Late Aircraft",
    "National Aviation System",
    "Security",
    "Total",
    "Weather"
})
@Generated("jsonschema2pojo")
public class MinutesDelayed {

    @JsonProperty("Carrier")
    private Integer carrier;
    @JsonProperty("Late Aircraft")
    private Integer lateAircraft;
    @JsonProperty("National Aviation System")
    private Integer nationalAviationSystem;
    @JsonProperty("Security")
    private Integer security;
    @JsonProperty("Total")
    private Integer total;
    @JsonProperty("Weather")
    private Integer weather;
    @JsonIgnore
    private Map<String, Object> additionalProperties = new HashMap<String, Object>();

    @JsonProperty("Carrier")
    public Integer getCarrier() {
        return carrier;
    }

    @JsonProperty("Carrier")
    public void setCarrier(Integer carrier) {
        this.carrier = carrier;
    }

    @JsonProperty("Late Aircraft")
    public Integer getLateAircraft() {
        return lateAircraft;
    }

    @JsonProperty("Late Aircraft")
    public void setLateAircraft(Integer lateAircraft) {
        this.lateAircraft = lateAircraft;
    }

    @JsonProperty("National Aviation System")
    public Integer getNationalAviationSystem() {
        return nationalAviationSystem;
    }

    @JsonProperty("National Aviation System")
    public void setNationalAviationSystem(Integer nationalAviationSystem) {
        this.nationalAviationSystem = nationalAviationSystem;
    }

    @JsonProperty("Security")
    public Integer getSecurity() {
        return security;
    }

    @JsonProperty("Security")
    public void setSecurity(Integer security) {
        this.security = security;
    }

    @JsonProperty("Total")
    public Integer getTotal() {
        return total;
    }

    @JsonProperty("Total")
    public void setTotal(Integer total) {
        this.total = total;
    }

    @JsonProperty("Weather")
    public Integer getWeather() {
        return weather;
    }

    @JsonProperty("Weather")
    public void setWeather(Integer weather) {
        this.weather = weather;
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
        sb.append(MinutesDelayed.class.getName()).append('@').append(Integer.toHexString(System.identityHashCode(this))).append('[');
        sb.append("carrier");
        sb.append('=');
        sb.append(((this.carrier == null)?"<null>":this.carrier));
        sb.append(',');
        sb.append("lateAircraft");
        sb.append('=');
        sb.append(((this.lateAircraft == null)?"<null>":this.lateAircraft));
        sb.append(',');
        sb.append("nationalAviationSystem");
        sb.append('=');
        sb.append(((this.nationalAviationSystem == null)?"<null>":this.nationalAviationSystem));
        sb.append(',');
        sb.append("security");
        sb.append('=');
        sb.append(((this.security == null)?"<null>":this.security));
        sb.append(',');
        sb.append("total");
        sb.append('=');
        sb.append(((this.total == null)?"<null>":this.total));
        sb.append(',');
        sb.append("weather");
        sb.append('=');
        sb.append(((this.weather == null)?"<null>":this.weather));
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
        result = ((result* 31)+((this.lateAircraft == null)? 0 :this.lateAircraft.hashCode()));
        result = ((result* 31)+((this.carrier == null)? 0 :this.carrier.hashCode()));
        result = ((result* 31)+((this.security == null)? 0 :this.security.hashCode()));
        result = ((result* 31)+((this.total == null)? 0 :this.total.hashCode()));
        result = ((result* 31)+((this.nationalAviationSystem == null)? 0 :this.nationalAviationSystem.hashCode()));
        result = ((result* 31)+((this.weather == null)? 0 :this.weather.hashCode()));
        result = ((result* 31)+((this.additionalProperties == null)? 0 :this.additionalProperties.hashCode()));
        return result;
    }

    @Override
    public boolean equals(Object other) {
        if (other == this) {
            return true;
        }
        if ((other instanceof MinutesDelayed) == false) {
            return false;
        }
        MinutesDelayed rhs = ((MinutesDelayed) other);
        return ((((((((this.lateAircraft == rhs.lateAircraft)||((this.lateAircraft!= null)&&this.lateAircraft.equals(rhs.lateAircraft)))&&((this.carrier == rhs.carrier)||((this.carrier!= null)&&this.carrier.equals(rhs.carrier))))&&((this.security == rhs.security)||((this.security!= null)&&this.security.equals(rhs.security))))&&((this.total == rhs.total)||((this.total!= null)&&this.total.equals(rhs.total))))&&((this.nationalAviationSystem == rhs.nationalAviationSystem)||((this.nationalAviationSystem!= null)&&this.nationalAviationSystem.equals(rhs.nationalAviationSystem))))&&((this.weather == rhs.weather)||((this.weather!= null)&&this.weather.equals(rhs.weather))))&&((this.additionalProperties == rhs.additionalProperties)||((this.additionalProperties!= null)&&this.additionalProperties.equals(rhs.additionalProperties))));
    }

}
