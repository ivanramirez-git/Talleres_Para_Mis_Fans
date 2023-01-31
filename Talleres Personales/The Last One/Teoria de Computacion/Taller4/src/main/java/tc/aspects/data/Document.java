package tc.aspects.data;

import tc.aspects.annotations.Auditable;
import tc.aspects.annotations.Auditable2;
import tc.aspects.annotations.Auditable4;

@Auditable2
public class Document {
    private Long id;
    private String title;
    private String issn;
    private Person owner;

    public Long getId() {
        System.out.println("Executing getId on " + this);
        return id;
    }

    @Auditable4
    public void setId(Long id) {
        System.out.println("Executing setId on " + this);
        this.id = id;
    }

    public String getTitle() {
        System.out.println("Executing getTitle on " + this);
        return title;
    }

    public void setTitle(String title) {
        System.out.println("Executing setTitle on " + this);
        this.title = title;
    }

    public String getIssn() {
        System.out.println("Executing getIssn on " + this);
        return issn;
    }

    public void setIssn(String issn) {
        System.out.println("Executing setIssn on " + this);
        this.issn = issn;
    }
    @Auditable
    public Person getOwner() {
        System.out.println("Executing getOwner on " + this);
        return owner;
    }

    @Auditable4
    public void setOwner(Person owner) {
        System.out.println("Executing setOwner on " + this);
        this.owner = owner;
    }

}
