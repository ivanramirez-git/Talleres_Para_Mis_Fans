package tc.aspects.data;

import tc.aspects.annotations.Auditable;

public class Person {
    String id;
    String name;
    String lastName;
    Integer age;

    public String getId() {
        System.out.println("executing getId on " + this);
        return id;
    }

    public void setId(String id) {
        System.out.println("executing setId on " + this);
        this.id = id;
    }
    @Auditable
    public String getName() {
        System.out.println("executing getName on " + this);
        return name;
    }

    public void setName(String name) {
        System.out.println("executing setName on " + this);
        this.name = name;
    }

    public String getLastName() throws Exception {
        System.out.println("executing getLastName on " + this);
        throw new Exception("This is an exception on " + this);
        
    }

    public void setLastName(String lastName) {
        System.out.println("executing setLastName on " + this);
        this.lastName = lastName;
    }

    public Integer getAge() {
        System.out.println("executing getAge on " + this);
        return age;
    }

    public void setAge(Integer age) {
        System.out.println("executing setAge on " + this);
        this.age = age;
    }

}
