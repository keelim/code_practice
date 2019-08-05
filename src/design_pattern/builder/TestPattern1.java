package design_pattern.builder;

public class TestPattern1 {
    public static void main(String[] args) {
        Person p1 = createPersonForTesting();
        System.out.println(p1.getFirstName());
        Person p2 = Person.personBuilder()
                .FirstName("sdsd")
                .AddressOne("aaa")
                .LastName("sdsd")
                .Married(true)
                .AddressTwo("2323")
                .DriverLicence(true)
                .Male_female("male")
                .build();

    }

    public static Person createPersonForTesting() { //기존 getter, setter
        Person person = new Person();
        person.setFirstName("FirstName");
        person.setLastName("LastName");
        person.setAddressOne("Address1");
        person.setAddressTwo("Address2");
        person.setMale_female("male");
        person.setDriverLicence(false);
        person.setMarried(true);

        return person;
    }
}





