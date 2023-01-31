
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
    "Cancelled",
    "Delayed",
    "Diverted",
    "On Time",
    "Total"
})
@Generated("jsonschema2pojo")
public class Flights {

    @JsonProperty("Cancelled")
    private Integer cancelled;
    @JsonProperty("Delayed")
    private Integer delayed;
    @JsonProperty("Diverted")
    private Integer diverted;
    @JsonProperty("On Time")
    private Integer onTime;
    @JsonProperty("Total")
    private Integer total;
    @JsonIgnore
    private Map<String, Object> additionalProperties = new HashMap<String, Object>();

    @JsonProperty("Cancelled")
    public Integer getCancelled() {
        return cancelled;
    }

    @JsonProperty("Cancelled")
    public void setCancelled(Integer cancelled) {
        this.cancelled = cancelled;
    }

    @JsonProperty("Delayed")
    public Integer getDelayed() {
        return delayed;
    }

    @JsonProperty("Delayed")
    public void setDelayed(Integer delayed) {
        this.delayed = delayed;
    }

    @JsonProperty("Diverted")
    public Integer getDiverted() {
        return diverted;
    }

    @JsonProperty("Diverted")
    public void setDiverted(Integer diverted) {
        this.diverted = diverted;
    }

    @JsonProperty("On Time")
    public Integer getOnTime() {
        return onTime;
    }

    @JsonProperty("On Time")
    public void setOnTime(Integer onTime) {
        this.onTime = onTime;
    }

    @JsonProperty("Total")
    public Integer getTotal() {
        return total;
    }

    @JsonProperty("Total")
    public void setTotal(Integer total) {
        this.total = total;
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
        sb.append(Flights.class.getName()).append('@').append(Integer.toHexString(System.identityHashCode(this))).append('[');
        sb.append("cancelled");
        sb.append('=');
        sb.append(((this.cancelled == null)?"<null>":this.cancelled));
        sb.append(',');
        sb.append("delayed");
        sb.append('=');
        sb.append(((this.delayed == null)?"<null>":this.delayed));
        sb.append(',');
        sb.append("diverted");
        sb.append('=');
        sb.append(((this.diverted == null)?"<null>":this.diverted));
        sb.append(',');
        sb.append("onTime");
        sb.append('=');
        sb.append(((this.onTime == null)?"<null>":this.onTime));
        sb.append(',');
        sb.append("total");
        sb.append('=');
        sb.append(((this.total == null)?"<null>":this.total));
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
        result = ((result* 31)+((this.diverted == null)? 0 :this.diverted.hashCode()));
        result = ((result* 31)+((this.total == null)? 0 :this.total.hashCode()));
        result = ((result* 31)+((this.onTime == null)? 0 :this.onTime.hashCode()));
        result = ((result* 31)+((this.cancelled == null)? 0 :this.cancelled.hashCode()));
        result = ((result* 31)+((this.delayed == null)? 0 :this.delayed.hashCode()));
        result = ((result* 31)+((this.additionalProperties == null)? 0 :this.additionalProperties.hashCode()));
        return result;
    }

    @Override
    public boolean equals(Object other) {
        if (other == this) {
            return true;
        }
        if ((other instanceof Flights) == false) {
            return false;
        }
        Flights rhs = ((Flights) other);
        return (((((((this.diverted == rhs.diverted)||((this.diverted!= null)&&this.diverted.equals(rhs.diverted)))&&((this.total == rhs.total)||((this.total!= null)&&this.total.equals(rhs.total))))&&((this.onTime == rhs.onTime)||((this.onTime!= null)&&this.onTime.equals(rhs.onTime))))&&((this.cancelled == rhs.cancelled)||((this.cancelled!= null)&&this.cancelled.equals(rhs.cancelled))))&&((this.delayed == rhs.delayed)||((this.delayed!= null)&&this.delayed.equals(rhs.delayed))))&&((this.additionalProperties == rhs.additionalProperties)||((this.additionalProperties!= null)&&this.additionalProperties.equals(rhs.additionalProperties))));
    }

}
