
//a) Assume collisions are handled by chaining. 

// h(12)=(2*12+5) mod 11 = 29 mod 11 =  7
// h(44)=(2*44+5) mod 11 = 93 mod 11 =  5
// h(13)=(2*13+5) mod 11 = 31 mod 11 =  9
// h(88)=(2*88+5) mod 11 = 181 mod 11 = 5
// h(23)=(2*23+5) mod 11 = 51 mod 11 =  7
// h(94)=(2*94+5) mod 11 = 193 mod 11 = 6
// h(11)=(2*11+5) mod 11 = 27 mod 11 =  5
// h(39)=(2*39+5) mod 11 = 83 mod 11 =  5
// h(20)=(2*20+5) mod 11 = 45 mod 11 =  1
// h(16)=(2*16+5) mod 11 = 37 mod 11 =  4
// h(5) =(2*5+5)  mod 11 = 15 mod 11 =  4

// Vị trí                          Chaining
//   0                                
//   1                                20
//   2                                
//   3                                
//   4                                16-->5
//   5                                44-->88-->11-->39
//   6                                94
//   7                                12-->23
//   8                                
//   9                                13
//  10                                

//b) Assume collisions are handled by linear probing. 

// h(12) = 7 
// h(44) = 5
// h(13) = 9
// h(88) = 5 (trùng => đến vị trí 6)
// h(23) = 7 (trùng => đến vị trí 8)
// h(94) = 6 (trùng => đến vị trí 10)
// h(11) = 5 (trùng => đến vị trí 0)
// h(39) = 5 (trùng => đến vị trí 1)
// h(20) = 1 (trùng => đến vị trí 2)
// h(16) = 4 
// h(5)  = 4 (trùng => đến vị trí 3)

// Vị trí                          linear probing
//   0                                   11
//   1                                   39
//   2                                   20
//   3                                   5
//   4                                   16
//   5                                   44
//   6                                   88 
//   7                                   12  
//   8                                   23  
//   9                                   13 
//  10                                   94  