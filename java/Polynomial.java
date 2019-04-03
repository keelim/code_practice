public class Polynomial {
    private List<Term> poly = new LinkedList<>();

    public Polynomial() {
        poly.addFirst(Term.ZERO);
    }

    public Polynomial(double coef, int exp) {
        poly.addFirst(Term.ZERO);
        poly.addFirst(new Term(coef, exp));
    }

    public Polynomial(Term term) {
        poly.addFirst(Term.ZERO);
        poly.addFirst(term);
    }

    public Polynomial(Term... terms) {
        poly.addFirst(Term.ZERO);

    }

    public void plus(Term term) {
        for (int i = 0; i < poly.size(); i++) {
            if (term.getExp() > poly.get(i).getExp()) {
                poly.add(i, term);
                break;
            } else if (term.getExp() == poly.get(i).getExp()) {
                poly.set(i, poly.get(i).plus(term));
                break;
            }
        }
    }

    public void plus(double coef, int exp) {
        Term term = new Term(coef, exp);
        for (int i = 0; i < poly.size(); i++) {
            if (term.getExp() > poly.get(i).getExp()) {
                poly.add(i, term);
                break;
            } else if (term.getExp() == poly.get(i).getExp()) {
                poly.set(i, poly.get(i).plus(term));
                break;
            }
        }
    }

    public Polynomial polyPlus(Polynomial otherPoly) {
        // polyPlus를 호출하고 있는 다항식과 인자로온 다른 다항식을 더한 새로운 다항식을 리턴
        // for each iterable이 구현이 안되어 사용 불가
        int max_origin, max_other, max_num, min_num;
        List<Double> temp_list1 = new LinkedList<>();
        List<Double> temp_list2 = new LinkedList<>();
        List<Integer> temp_list3 = new LinkedList<>();
        List<Integer> temp_list4 = new LinkedList<>();
        List<Double> temp_list5 = new LinkedList<>();
        List<Double> temp_list6 = new LinkedList<>();
        List<Double> temp_list7 = new LinkedList<>();
        Polynomial answerpoly = new Polynomial();

        max_origin = poly.get(0).getExp() + 1; // 높은 차수를 구해서 차수+1 크기의 리스트 생성
        max_other = otherPoly.poly.get(0).getExp() + 1;
        max_num = (max_origin > max_other) ? max_origin : max_other;

        for (int i = 0; i < max_num; i++) {
            temp_list1.addFirst(0.0); // 값 참조 리스트1
            temp_list2.addFirst(0.0); // 값 참조 리스트
            temp_list3.addFirst(0); // 인덱스 참조 리스트1
            temp_list4.addFirst(0); // 인덱스 참조 리스트2
            temp_list5.addFirst(0.0); // 변환 리스트1
            temp_list6.addFirst(0.0); // 변환 리스트2
        }

        for (int i = 0; i < poly.size(); i++) { // 기존 폴리노미얼 리스트 생성
            temp_list1.set(i, poly.get(i).getCoef());
            temp_list3.set(i, poly.get(i).getExp());
        }
        for (int i = 0; i < otherPoly.poly.size(); i++) { // otherPoly 에서 리스트 생성
            temp_list2.set(i, otherPoly.poly.get(i).getCoef());
            temp_list4.set(i, otherPoly.poly.get(i).getExp());
        }

        for (int i = 0; i < temp_list3.size(); i++) { // 변환 리스트 생성 - origin
            if (temp_list3.get(i) == -1)
                break;
            temp_list5.set(max_num - 1 - temp_list3.get(i), temp_list1.get(i));
        }

        for (int i = 0; i < temp_list4.size(); i++) { // 변환 리스트 생성 - otherPoly
            if (temp_list4.get(i) == -1)
                break;
            temp_list6.set(max_num - 1 - temp_list4.get(i), temp_list2.get(i));
        }
        // 변환 리스트 생성 완료
        for (int i = 0; i < max_num; i++) {
            temp_list7.addLast(temp_list5.get(i) + temp_list6.get(i)); // 최종 리스트
        }

        for (int i = 0; i < temp_list7.size(); i++) {
            if (temp_list7.get(i) == 0)
                continue; // coef 가 0인 텀을 만나면 다음 루프로 넘어간다.
            answerpoly.plus(new Term(temp_list7.get(i), max_num - 1 - i)); // 변환 리스트 coef 를 Term으로 생성
        }

        return answerpoly;

    }

    public String toString() {
        StringBuilder str = new StringBuilder(poly.get(0).toString());

        for (int i = 1; i < poly.size() - 1; i++)
            if (poly.get(i).getCoef() > 0)
                str.append(" +" + poly.get(i));
            else
                str.append(poly.get(i));
        return new String(str);
    }

    public static void main(String[] arg) {
        Polynomial f = new Polynomial(new Term(1, 1)); // 다항식 f를 생성
        f.plus(new Term(3, 3)); // x Term에 3x^3 Term을 연결
        f.plus(new Term(2, 2)); // 3x^3 + x에 2x^2 Term을 연결
        f.plus(new Term(7, 0));

        Polynomial g = new Polynomial();

        g.plus(new Term(4, 4));
        g.plus(new Term(5, 5));
        g.plus(new Term(1, 2));
        g.plus(new Term(2, 3));

        System.out.println("f(x) = " + f);
        System.out.println("g(x) = " + g);

        Polynomial z = g.polyPlus(f);
        System.out.println("f(x) + g(x) = " + z);

    }
}
