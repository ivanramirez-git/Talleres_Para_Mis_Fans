package tc.aspects;

import tc.aspects.data.Document;
import tc.aspects.data.Person;
import tc.aspects.data.Student;
import tc.aspects.data.Teacher;
import tc.aspects.data.University;

public class UniversityApplication {
    public void run() {
        Person p = new Person();
        Student s = new Student();
        Teacher t = new Teacher();
        Document d = new Document();
        University u = new University();

        p.setAge(10);
        p.setId("111");
        p.setName("aaa");
        p.getAge();
        p.getId();
        p.getName();

        s.setAge(20);
        s.setId("222");
        s.setName("bbb");
        s.getAge();
        s.getId();
        s.getName();

        t.setAge(30);
        t.setId("333");
        t.setName("ccc");
        t.getAge();
        t.getId();
        t.getName();

        d.setId(333l);
        d.setTitle("ddd");
        d.setIssn("11111");
        d.setOwner(p);
        d.getId();
        d.getTitle();
        d.getIssn();
        d.getOwner();
        

        u.addTeacher("30", "tttt", "ttttt", 40);

        u.getTeacherNames();

    }

    public static void main(String[] args) {
        new UniversityApplication().run();
    }
}
