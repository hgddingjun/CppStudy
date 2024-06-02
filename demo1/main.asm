
main.o：     文件格式 elf64-x86-64


Disassembly of section .text:

0000000000000000 <main>:
#include <string>

using namespace std;

int main()
{
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   rbp
   5:	48 89 e5             	mov    rbp,rsp
   8:	53                   	push   rbx
   9:	48 83 ec 48          	sub    rsp,0x48
   d:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
  14:	00 00 
  16:	48 89 45 e8          	mov    QWORD PTR [rbp-0x18],rax
  1a:	31 c0                	xor    eax,eax
    string name = "***dingjun Hello!***";
  1c:	48 8d 45 bf          	lea    rax,[rbp-0x41]
  20:	48 89 c7             	mov    rdi,rax
  23:	e8 00 00 00 00       	call   28 <main+0x28>
  28:	48 8d 55 bf          	lea    rdx,[rbp-0x41]
  2c:	48 8d 45 c0          	lea    rax,[rbp-0x40]
  30:	48 8d 35 00 00 00 00 	lea    rsi,[rip+0x0]        # 37 <main+0x37>
  37:	48 89 c7             	mov    rdi,rax
  3a:	e8 00 00 00 00       	call   3f <main+0x3f>
  3f:	48 8d 45 bf          	lea    rax,[rbp-0x41]
  43:	48 89 c7             	mov    rdi,rax
  46:	e8 00 00 00 00       	call   4b <main+0x4b>
    cout << "Hello world!" << endl;
  4b:	48 8d 35 00 00 00 00 	lea    rsi,[rip+0x0]        # 52 <main+0x52>
  52:	48 8d 3d 00 00 00 00 	lea    rdi,[rip+0x0]        # 59 <main+0x59>
  59:	e8 00 00 00 00       	call   5e <main+0x5e>
  5e:	48 89 c2             	mov    rdx,rax
  61:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 68 <main+0x68>
  68:	48 89 c6             	mov    rsi,rax
  6b:	48 89 d7             	mov    rdi,rdx
  6e:	e8 00 00 00 00       	call   73 <main+0x73>
    cout << name << endl;
  73:	48 8d 45 c0          	lea    rax,[rbp-0x40]
  77:	48 89 c6             	mov    rsi,rax
  7a:	48 8d 3d 00 00 00 00 	lea    rdi,[rip+0x0]        # 81 <main+0x81>
  81:	e8 00 00 00 00       	call   86 <main+0x86>
  86:	48 89 c2             	mov    rdx,rax
  89:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 90 <main+0x90>
  90:	48 89 c6             	mov    rsi,rax
  93:	48 89 d7             	mov    rdi,rdx
  96:	e8 00 00 00 00       	call   9b <main+0x9b>
    return 0;
  9b:	bb 00 00 00 00       	mov    ebx,0x0
    string name = "***dingjun Hello!***";
  a0:	48 8d 45 c0          	lea    rax,[rbp-0x40]
  a4:	48 89 c7             	mov    rdi,rax
  a7:	e8 00 00 00 00       	call   ac <main+0xac>
  ac:	89 d8                	mov    eax,ebx
}
  ae:	48 8b 4d e8          	mov    rcx,QWORD PTR [rbp-0x18]
  b2:	64 48 33 0c 25 28 00 	xor    rcx,QWORD PTR fs:0x28
  b9:	00 00 
  bb:	74 43                	je     100 <main+0x100>
  bd:	eb 3c                	jmp    fb <main+0xfb>
  bf:	f3 0f 1e fa          	endbr64 
  c3:	48 89 c3             	mov    rbx,rax
  c6:	48 8d 45 bf          	lea    rax,[rbp-0x41]
  ca:	48 89 c7             	mov    rdi,rax
  cd:	e8 00 00 00 00       	call   d2 <main+0xd2>
  d2:	48 89 d8             	mov    rax,rbx
  d5:	48 89 c7             	mov    rdi,rax
  d8:	e8 00 00 00 00       	call   dd <main+0xdd>
  dd:	f3 0f 1e fa          	endbr64 
  e1:	48 89 c3             	mov    rbx,rax
    string name = "***dingjun Hello!***";
  e4:	48 8d 45 c0          	lea    rax,[rbp-0x40]
  e8:	48 89 c7             	mov    rdi,rax
  eb:	e8 00 00 00 00       	call   f0 <main+0xf0>
  f0:	48 89 d8             	mov    rax,rbx
  f3:	48 89 c7             	mov    rdi,rax
  f6:	e8 00 00 00 00       	call   fb <main+0xfb>
}
  fb:	e8 00 00 00 00       	call   100 <main+0x100>
 100:	48 83 c4 48          	add    rsp,0x48
 104:	5b                   	pop    rbx
 105:	5d                   	pop    rbp
 106:	c3                   	ret    

0000000000000107 <_Z41__static_initialization_and_destruction_0ii>:
 107:	f3 0f 1e fa          	endbr64 
 10b:	55                   	push   rbp
 10c:	48 89 e5             	mov    rbp,rsp
 10f:	48 83 ec 10          	sub    rsp,0x10
 113:	89 7d fc             	mov    DWORD PTR [rbp-0x4],edi
 116:	89 75 f8             	mov    DWORD PTR [rbp-0x8],esi
 119:	83 7d fc 01          	cmp    DWORD PTR [rbp-0x4],0x1
 11d:	75 32                	jne    151 <_Z41__static_initialization_and_destruction_0ii+0x4a>
 11f:	81 7d f8 ff ff 00 00 	cmp    DWORD PTR [rbp-0x8],0xffff
 126:	75 29                	jne    151 <_Z41__static_initialization_and_destruction_0ii+0x4a>
  extern wostream wclog;	/// Linked to standard error (buffered)
#endif
  //@}

  // For construction of filebuffers for cout, cin, cerr, clog et. al.
  static ios_base::Init __ioinit;
 128:	48 8d 3d 00 00 00 00 	lea    rdi,[rip+0x0]        # 12f <_Z41__static_initialization_and_destruction_0ii+0x28>
 12f:	e8 00 00 00 00       	call   134 <_Z41__static_initialization_and_destruction_0ii+0x2d>
 134:	48 8d 15 00 00 00 00 	lea    rdx,[rip+0x0]        # 13b <_Z41__static_initialization_and_destruction_0ii+0x34>
 13b:	48 8d 35 00 00 00 00 	lea    rsi,[rip+0x0]        # 142 <_Z41__static_initialization_and_destruction_0ii+0x3b>
 142:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 149 <_Z41__static_initialization_and_destruction_0ii+0x42>
 149:	48 89 c7             	mov    rdi,rax
 14c:	e8 00 00 00 00       	call   151 <_Z41__static_initialization_and_destruction_0ii+0x4a>
 151:	90                   	nop
 152:	c9                   	leave  
 153:	c3                   	ret    

0000000000000154 <_GLOBAL__sub_I_main>:
 154:	f3 0f 1e fa          	endbr64 
 158:	55                   	push   rbp
 159:	48 89 e5             	mov    rbp,rsp
 15c:	be ff ff 00 00       	mov    esi,0xffff
 161:	bf 01 00 00 00       	mov    edi,0x1
 166:	e8 9c ff ff ff       	call   107 <_Z41__static_initialization_and_destruction_0ii>
 16b:	5d                   	pop    rbp
 16c:	c3                   	ret    
