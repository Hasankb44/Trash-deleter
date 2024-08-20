package trashdeleter;

public class Main {
    static {
        Runtime.getRuntime().load("C:\\Users\\ruyak\\OneDrive\\Masaüstü\\JNI\\src\\main\\java\\trashdeleter\\extern.dll");
    }

    private long id;

    public Main(long id) {
        this.id = id;
    }

    public native void createAndDeleteWeakReference(Main obj);

    public static void main(String[] args) {
        Main myObject = new Main(12345);
        myObject.createAndDeleteWeakReference(myObject);


    }
}
