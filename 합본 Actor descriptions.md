#### Actor descriptions (합본)

| Actor                                | Description                                                  |
| :----------------------------------- | ------------------------------------------------------------ |
| 회원                                    | 회원가입/회원탈퇴, 로그인/로그아웃을 할 수 있다. |
| 판매자                                 | 의류등록, 등록중인 상품 리스트 조회, 수정, 삭제, 상품 판매통계, 판매 완료된 상품내역 조회를 할 수 있다.                             |
| 구매자                                 | 상품정보를 조회, 상품 구매, 포인트적립, 구매내역조회, 상품구매내역 삭제, 환불 신청, 상품 구매통계를 할 수 있다.                       |
| 택배사                               | 환불을 신청할 때 택배사에 자동으로 물품 수거 신청이 요청된다. |
| 6개월이 지난 거래내역 자동삭제 event       | 6개월이 지난 거래내역은 자동으로 삭제된다.                   |
| 매월 말일 event                      | 매월 말일마다 모든 회원에게 통계정보 보내야한다.             |
| 이메일 시스템                        | 모든 회원들에게 그 달에 대한 판매 및 구매 통계 정보가 이메일로 공지된다. |
| 환불 event                            | 상품이 환불되는 경우 적립되었던 포인트를 반환한다.                        |
