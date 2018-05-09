# x86ASM
studying x86 assembly

##Registers
###General Register(Littel Endian)
(Extended : 16->32bit로 확장 되면서 명명)
xxxx xxxx AX(AH(xxxx) AL(xxxx))
////////////////////////////////////////////////////
데이터
////////////////////////////////////////////////////
EAX : Extended Accumulator Register
산술, 논리

EDX : Extended Data Register
EAX 보조

EBX : Extended Base Register
ESI, EDI와 결합, 메모리주소 저장

ECX : Extended Counter Register
반복문의 카운터
///////////////////////////////////////////////////
주소
////////////////////////////////////////////////////
ESI : Extended Source Index Register
데이터 조작, 복사시의 소스 데이터

EDI : Extended Destination Index Register
복사시 목적지 주소

ESP : Extended Stack Point Register
스택 프레임 가장 끝 주소

EBP : Extended Base Point Register
스택 프레임 가장 첫 주소
스택 프레임이 소멸하지 않는 한 고정
////////////////////////////////////////////////////
###Program Counter
EIP : Extended Instruction Pointer register
다음에 실행할 명령어의 주소

###Command
-32bit 메모리는 한 주소당 32bit 크기를 가지며, 주소 번호역시 마찬가지다.
즉 0~2**32-1 개의 주소를 갖고, 당연히 해당 크기의 데이터를 저장 가능하다
즉 4GB가 32bit cpu에 대응 되는 최대 메모리 크기이다.

QWORD 8B
DWORD 4B
WORD 2B //컴퓨터 구조의 워드 개념과 헷갈리지 말 것 (확장 된 것이다보니)
BYTE 1B

memory : [base address + (offset) + (index) * scale], offset은 byte 단위임
register는 2개까지, index는 register만 가능

mov b, a a의 값을 b로 이동 (저장 공간 크기가 같아야 함)
<size> ptr ds:[0x--------] 메모리의 주소

cmp a, b 비교. 내부적으로 뺄셈으로 구현. (a -b를 하고 그 값을 a에 저장하진 않음) => 같으면 0, 즉 ZF를 1로 만듬.

nop : 아무것도 안함

inc / dec : 증 / 감 +1 / -1
inc address

add / sub : 증 / 감 +n / -n
add address, val

####Condition
{cmd} {address}
상태 레지스터 C P A Z S T D O /bit단위

CF : CarryFlag // 직전 연산에서 carry가 발생했을 때 flag on(2진수 연산의 올림수)
ZF : ZeroFlag // 직전 연산이 0일때 flag on


jmp : 해당 주소로 점프 (무조건 점프)
jmp {short} address
(short : signed int 내로 주소간의 거리가 표현이 가능할 때 즉 128~-127 일 때)

ja(jnbe) : CF off + "ZF off"일 때 점프   //jump if above //cmp 왼쪽이 더 클 때, 캐리 발생 안함
jb(jc)(jnae) : CF on일 때 점프    //jump if below //cmp 오른쪽이 더 클 때, 캐리 발생
jae(jnb) >=
jbe(jna) <=

jz(je) : ZF on일 때 점프    //jump if zero
jnz(jne) : ZF off일 때 점프



///////////////////////////////////////////////////////
###Byte Order
1바이트 단위로 저장.
리틀엔디안은 LSB부터, 빅엔디안은 MSB부터
즉, 89ABCDEF 이라 치면
리틀엔디안 : EF CD AB 89
빅  엔디안 : 89 AB CD EF
전자는 LSB부터 읽어야 할 경우 더 빠르고,
후자는 디버깅하기 더 쉽지