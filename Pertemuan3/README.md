1. Cara kerja lengan bergerak
   bagian lengan terdiri dari shoulder, lengan atas, siku, lengan bawah. Jika shoulder bergerak, seluruh lengan ikut bergerak. Tetapi jika siku yang bergerak, hanya lengan bawah yang ikut gerak.
   - menggunakan translasi untuk memindahkan pivot
   - menggunakan rotasi untuk memutar sendi
   - menggunakan scale untuk membentuk lengan
   - pergerakan menggunakan inputan keyboard user
   
   Struktur : Shoulder -> Lengan Atas -> Siku -> Lengan Bawah

2. Menambahkan telapak tangan beserta jari-jari dari lengan di atas
   - menambahkan objek wrist dan finger1-5
     
     <img width="148" height="86" alt="nambah objek" src="https://github.com/user-attachments/assets/d9c0fd74-57ff-4cf6-8fb0-ea907a060b6a" />

   - membuat objeknya
     
     <img width="236" height="546" alt="buat objek" src="https://github.com/user-attachments/assets/d1387730-1265-4fce-a4c0-1b102106895d" />

   - kontrol keyboard
     
     <img width="219" height="303" alt="kontrol keyboard" src="https://github.com/user-attachments/assets/188b4b2d-c525-4c9b-8a13-15a0fbaeba8e" />

   <img width="805" height="632" alt="lengan + jari" src="https://github.com/user-attachments/assets/4f65b095-dd26-46bb-aa38-4880e4408b93" />

3. Simulasi menggunakan sumbu x,y,z bagaimana operasi yang dilakukan ketika keyboard di ketik
   - rotasi pada program menggunakan glRotatef(angle, 0, 0, 1) artinya rotasi terhadap sumbu Z, sehingga gerakan terjadi pada bidang X-Y. Simulasi dilakukan menggunakan grid sebagai milimeter block dan sumbu koordinat X, Y. Sumbu X berwarna merah, sumbu Y berwarna hijau
     
   - Posisi awal
     
     <img width="606" height="410" alt="image" src="https://github.com/user-attachments/assets/49d1aa30-b908-4647-bef2-232dc036fb28" />

   - Shoulder diputar
     
     <img width="605" height="410" alt="image" src="https://github.com/user-attachments/assets/413e5164-d8d1-4fc8-ba3c-fc4bcda19979" />


