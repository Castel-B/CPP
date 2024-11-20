#include <iostream>
#include <iomanip>
using namespace std;

int password, pin, ePay = 10000;
void menuUser(string daftarBarang[], int hargaBarang[], int total_barang, bool &program, string username, int &ePay, int stockBarang[]);
void menuAdmin(string daftarBarang[], int hargaBarang[], int &total_barang, bool &program, int stockBarang[]);
void tampilkanBarang(string daftarBarang[], int hargaBarang[], int total_barang, int stockBarang[]);
void kelolaBarang(string daftarBarang[], int hargaBarang[], int &total_barang, int stockBarang[]);
void tambahBarang(string daftarBarang[], int hargaBarang[], int &total_barang, int stockBarang[]);
void hapusBarang(string daftarBarang[], int hargaBarang[], int &total_barang, int stockBarang[]);
bool checkLogin(string username, string password, int a, string akun[100][2], bool &admin);

int main()
{
    bool akunada = false;
    int a = 0;
    string username, password;
    string akun[100][2];
    int max_items = 100, hargaBarang[max_items], total_barang = 0, menuLogin, stockBarang[max_items];
    string daftarBarang[max_items];

    int life = 2, coba = 2;
    bool program = true, admin = false;

    while (life >= 0 && program)
    {
        system("cls");
        cout << setw(30) << setfill('=') << "\n";
        cout << "         Selamat datang\n";
        cout << setw(30) << setfill('=') << "\n";
        cout << "1. Login\n";
        cout << "2. Sign in\n";
        cout << "Pilihan : \n";
        cin >> menuLogin;

        switch (menuLogin)
        {
        case 1:
            system("cls");
            if (a == 0)
            {
                cout << "Belum ada akun yang terdaftar!\nHarap buat akun terlebih dahulu...\n";
                cin.ignore();
                cin.get();
            }
            else
            {
                cout << "Username : ";
                cin >> username;
                cout << "Password : ";
                cin >> password;
                checkLogin(username, password, a, akun, admin);
                if (checkLogin(username, password, a, akun, admin) == true)
                {
                    cout << "anda berhasil login!\n";
                    cin.ignore();
                    cin.get();
                    if (admin == true)
                    {
                        menuAdmin(daftarBarang, hargaBarang, total_barang, program, stockBarang);
                    }
                    else
                    {
                        menuUser(daftarBarang, hargaBarang, total_barang, program, username, ePay, stockBarang);
                    }
                }
                else
                {
                    cout << "Username / password salah!\nTersisa " << life << "x percobaan login lagi!\n";
                    cin.ignore();
                    cin.get();
                    life--;
                }
            }
            break;

        case 2:
            system("cls");
            cout << "Masukkan username anda : ";
            cin >> akun[a][0];
            cout << "Masukkan PIN anda : ";
            cin >> akun[a][1];
            for (int i = 0; i < a; i++)
            {
                if (akun[a][0] == akun[i][0])
                {
                    akunada = true;
                }
            }
            if (akunada == true)
            {
                cout << "Username " << akun[a][0] << " sudah ada!\nGunakan username lain.\n";
            }
            else
            {

                cout << "Selamat akun dengan username " << akun[a][0] << " berhasil dibuat!\n";
                cout << "Lanjutkan login...\n";
                a++;
            }
            cin.ignore();
            cin.get();
            break;

        default:
            cout << "Error!\n Invalid Process!";
            cin.ignore();
            cin.get();
            break;
        }
    }
    return 0;
}

void menuUser(string daftarBarang[], int hargaBarang[], int total_barang, bool &program, string username, int &ePay, int stockBarang[])
{
    int pilihan;
    bool keluar = false;

    while (!keluar)
    {
        system("cls");
        cout << setw(30) << setfill('=') << "\n";
        cout << "           Menu User\n";
        cout << setw(30) << setfill('=') << "\n";
        cout << "1. Market Place\n";
        cout << "2. Profile saya\n";
        cout << "3. Top up E-Pay\n";
        cout << "4. Riwayat Pembelian\n";
        cout << "5. Kembali ke menu login\n";
        cout << "6. Keluar\n";
        cout << setw(30) << setfill('=') << "\n";
        cout << "Pilihan anda : ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            system("cls");
            cout << setw(70) << setfill('=') << "\n";
            cout << "                             Market Place\n";
            cout << setw(70) << setfill('=') << "\n";
            tampilkanBarang(daftarBarang, hargaBarang, total_barang, stockBarang);
            cin.ignore();
            cin.get();
            break;

        case 2:
            system("cls");
            cout << setw(70) << setfill('=') << "\n";
            cout << "                            Profile Saya\n";
            cout << setw(70) << setfill('=') << "\n";
            cout << username << endl
                 << endl;
            cout << "Saldo E-Pay anda : " << ePay;
            cin.ignore();
            cin.get();
            break;

        case 3:
            cout << " ";
            break;

        case 5:
            keluar = true;
            break;

        case 6:
            keluar = true;
            program = false;
            break;

        default:
            cout << "Pilihan tidak valid!\n";
            cin.ignore();
            cin.get();
            break;
        }
    }
}

void menuAdmin(string daftarBarang[], int hargaBarang[], int &total_barang, bool &program, int stockBarang[])
{
    int pilihan;
    bool keluar = false;

    while (!keluar)
    {
        system("cls");
        cout << setw(30) << setfill('=') << "\n";
        cout << "           Menu Admin\n";
        cout << setw(30) << setfill('=') << "\n";
        cout << "1. Menampilkan semua barang\n";
        cout << "2. Kelola barang\n";
        cout << "3. Kembali ke menu login\n";
        cout << "4. Keluar\n";
        cout << setw(30) << setfill('=') << "\n";
        cout << "Pilihan anda : ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            system("cls");
            tampilkanBarang(daftarBarang, hargaBarang, total_barang, stockBarang);
            cin.ignore();
            cin.get();
            break;

        case 2:
            kelolaBarang(daftarBarang, hargaBarang, total_barang, stockBarang);
            break;

        case 3:
            keluar = true;
            break;

        case 4:
            keluar = true;
            program = false;
            break;

        default:
            cout << "Pilihan tidak valid!\n";
            cin.ignore();
            cin.get();
            break;
        }
    }
}

void tampilkanBarang(string daftarBarang[], int hargaBarang[], int total_barang, int stockBarang[])
{
    system("cls");

    cout << setw(71) << setfill('=') << "\n";
    cout << setw(40) << setfill(' ') << "Market Place\n";
    cout << setw(72) << setfill('=') << "\n\n";
    cout << setfill(' ');
    cout << left << setw(5) << "No"
         << setw(30) << "Nama Barang"
         << right << setw(20) << "Harga"
         << endl;
    cout << setw(71) << setfill('=') << "\n";
    setfill(' ');

    if (total_barang == 0)
    {
        cout << "Belum ada barang yang tersedia.\n";
    }
    else
    {
        for (int i = 0; i < total_barang; i++)
        {
            cout << left << setw(5) << setfill(' ') << i + 1
                 << setw(30) << setfill(' ') << daftarBarang[i]
                 << right << setw(17) << setfill(' ') << "Rp. "
                 << setw(3) << hargaBarang[i] << endl;
        }
    }
    cout << setw(71) << setfill('=') << "\n";
}

void kelolaBarang(string daftarBarang[], int hargaBarang[], int &total_barang, int stockBarang[])
{

    int pilihan;
    bool keluar = false;
    while (!keluar)
    {
        system("cls");
        cout << setw(30) << setfill('=') << "\n";
        cout << "         Kelola Barang\n";
        cout << setw(30) << setfill('=') << "\n";
        cout << "1. Tambahkan barang\n";
        cout << "2. Hapus barang\n";
        cout << "3. Kembali ke menu admin\n";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            tambahBarang(daftarBarang, hargaBarang, total_barang, stockBarang);
            break;

        case 2:
            hapusBarang(daftarBarang, hargaBarang, total_barang, stockBarang);
            break;

        case 3:
            keluar = true;
            break;

        default:
            cout << "Pilihan anda tidak valid!\n";
            cin.ignore();
            cin.get();
            break;
        }
    }
}

void tambahBarang(string daftarBarang[], int hargaBarang[], int &total_barang, int stockBarang[])
{
    system("cls");
    cout << "Masukkan nama barang yang ingin ditambahkan : ";
    cin.ignore();
    getline(cin, daftarBarang[total_barang]);
    cout << "Masukkan harga barang : ";
    cin >> hargaBarang[total_barang];
    cout << "Masukkan Jumlah stock : ";
    cin >> stockBarang[total_barang];
    total_barang++;
    cout << "Barang berhasil ditambahkan.\n";
}

void hapusBarang(string daftarBarang[], int hargaBarang[], int &total_barang, int stockBarang[])
{

    bool lanjut = true;
    int nomor;
    char pilihan;
    while (lanjut)
    {
        system("cls");
        tampilkanBarang(daftarBarang, hargaBarang, total_barang, stockBarang);

        cout << "Masukkan nomor barang yang ingin dihapus : ";
        cin >> nomor;

        if (nomor > 0 && nomor <= total_barang)
        {
            for (int i = nomor - 1; i < total_barang - 1; i++)
            {
                daftarBarang[i] = daftarBarang[i + 1];
                hargaBarang[i] = hargaBarang[i + 1];
                stockBarang[i] = stockBarang[i + 1];
            }
            total_barang--;

            daftarBarang[total_barang] = "";
            hargaBarang[total_barang] = 0;
            stockBarang[total_barang] = 0;
            cout << "Barang berhasil dihapus dari list.\n";
            cout << setw(30) << setfill('-') << "\n";
            cout << "Apakah anda ingin melanjutkan (y/n)?  ";
            cin >> pilihan;

            switch (tolower(pilihan))
            {
            case 'n':
                lanjut = false;
                break;

            case 'y':
                break;

            default:
                cout << "Pilihan tidak valid!\n";
                cin.ignore();
                cin.get();
                continue;
            }
        }
        else
        {
            cout << "Nomor yang dimasukkan tidak valid!\n";
            lanjut = false;
            cin.ignore();
            cin.get();
        }
    }
}

bool checkLogin(string username, string password, int a, string akun[100][2], bool &admin)
{
    bool find = false;

    for (int i = 0; i < a; i++)
    {
        if (username == akun[i][0] && password == akun[i][1])
        {
            find = true;
        }
        else if (username == "admin" && password == "admin123")
        {
            find = true;
            admin = true;
        }
    }
    if (find == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}