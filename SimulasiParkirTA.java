import java.util.LinkedList;
import java.util.Scanner;
import java.io.IOException;
import java.util.concurrent.TimeUnit;

public class SimulasiParkirTA {
    public static void main(String[] args) throws InterruptedException {
        Scanner input = new Scanner(System.in);
        boolean condition = true;

        Parkir.awalQueue();
        Parkir.tampilParkir();

        while (condition) {
            System.out.println("\n========== SIMULASI PARKIR ==========");
            System.out.println("1. Masukkan Mobil");
            System.out.println("2. Keluar Mobil");
            System.out.println("3. Program Keluar");
            System.out.println("=====================================");

            System.out.print("Pilih (1/2/3): ");
            String k = input.nextLine();
            switch (k) {
                case "1" -> Parkir.add();
                case "2" -> Parkir.del();
                case "3" -> {
                    System.out.println("\nProgram Keluar.....");
                    condition = false;
                    TimeUnit.SECONDS.sleep(1);
                }
                default -> {
                    Parkir.clrscr();
                    System.out.println("\nInput Salah. Ulangi Kembali");
                    Parkir.tampilParkir();
                }
            }
        }
    }
}

class Parkir {
    public static LinkedList<String> park = new LinkedList<>();
    public static String[] temp = new String[10];
    static Scanner input2 = new Scanner(System.in);
    static int rear;

    //======================================= PARKIR QUEUE & STACK =======================================

    static void awalQueue() {
        rear = -1;
        for (int i = 0; i < 10; i++) {
            park.add("---");
        }
    }

    static void add() {
        System.out.print("Masukkan Nomor Plat yang akan masuk: ");
        String nopol = input2.nextLine();
        rear += 1;
        clrscr();

        if (rear < 10) {
            park.add(rear, nopol);
            park.removeLast();
        } else {
            System.out.println("PARKIR PENUH");
            rear -= 1;
        }

        tampilParkir();
    }

    static void del() {
        int selesai = 0;
        int loop = 0;
        while (loop == 0) {
            System.out.print("Masukkan Urutan Mobil yang akan keluar: ");
            try {
                String keluar = input2.nextLine();
                selesai = Integer.parseInt(keluar);
                loop = 1;
            } catch (NumberFormatException e) {
                System.out.println("Input Berupa Angka!");
                loop = 0;
            }
        }

        System.out.println(); selesai -= 1;
        clrscr();

        if (selesai > rear) {
            System.out.println("Mobil pada urutan " + (selesai+1) + " tidak ada");
            tampilParkir();
            return;
        }

        for (int i = 0; i < selesai; i++) {
            // PUSH
            temp[i] = park.get(0);
            park.remove(0);
            System.out.println("- Mobil " + temp[i] + " Keluar terlebih dahulu");
        }

        System.out.println("- Mobil " + park.get(0) + " Keluar dari tempat parkir");
        park.remove(0);
        rear -= 1;

        for (int j = selesai - 1; j >= 0; j--) {
            // POP
            park.add(0, temp[j]);
            System.out.println("- Mobil " + temp[j] + " sudah kembali");
        }

        park.addLast("---");
        tampilParkir();
    }

    static void tampilParkir() {
        if (park.isEmpty()) {
            System.out.println("\nPARKIR KOSONG");
        } else {
            System.out.println("\nKELUAR Selatan (Depan)\n=============");
            for (String s : park) {
                System.out.println(" " + s + " ");
            }
            System.out.println("=============\nMASUK Utara (Belakang)");
        }
    }

    static void clrscr() {
        try {
            if (System.getProperty("os.name").contains("Windows"))
                new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
            else
                Runtime.getRuntime().exec("clear");
        } catch (IOException | InterruptedException ignored) {

        }
    }
}
