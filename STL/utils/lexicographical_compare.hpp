#ifndef FT_LEXICOGRAPHICAL_COMPARE
#define FT_LEXICOGRAPHICAL_COMPARE

namespace ft {
		// ALGORITHM STUFF
	template <class InIt, class OutIt> inline
	OutIt copy (InIt F, InIt L, OutIt X)
    {
		for (; F != L; ++X, ++F)
			*X = *F;
		return (X);
	}

	template <class BidIt1, class BidIt2> inline
	BidIt2 copy_backward(BidIt1 F, BidIt1 L, BidIt2 X)
    {
		while (F != L)
			*--X = *--L;
		return (X);
	}

	// template <class InIt1, class InIt2> inline
	// pair<InIt1, InIt2> mismatch(InIt1 F, InIt1 L, InIt2 X)
    // {
	// 		for (; F != L && *F == *X; ++F, ++X)
	// 			;
	// 		return (pair<InIt1, InIt2>(F, X));
	// }

	// template <class InIt1, class InIt2, class Pr> inline
	// pair<InIt1, InIt2> mismatch(InIt1 F, InIt1 L, InIt2 X, Pr P) {
	// 	for (; F != L && P(*F, *X); ++F, ++X)
	// 		;
	// 	return (pair<InIt1, InIt2>(F, X));
	// }

	template <class InIt1, class InIt2> inline
		bool equal (InIt1 F, InIt1 L, InIt2 X) {
			return (ft::mismatch(F, L, X).first == L);
		}
	
	template <class InIt1, class InIt2, class Pr> inline
		bool equal (InIt1 F, InIt1 L, InIt2 X, Pr P) {
			return (ft::mismatch(F, L, X, P).first == L);
		}

	template<class FwdIt, class T> inline
		void fill (FwdIt F, FwdIt L, const T& X) {
			for (; F != L; ++F)
				*F = X;
		}

	template<class OutIt, class Sz, class T> inline
		void fill (OutIt F, Sz N, const T& X) {
			for (; 0 < N; --N, ++F)
				*F = X;
		}

	template<class InIt1, class InIt2> inline
		bool lexicographical_compare(InIt1 F1, InIt1 L1,
		InIt2 F2, InIt2 L2) {
			for (; F1 != L1 && F2 != L2; ++F1, ++F2)
				if (*F1 < *F2)
					return (true);
				else if (*F2 < *F1)
					return (false);
			return (F1 == L1 && F2 != L2);
		}

	template<class InIt1, class InIt2, class Pr> inline
		bool lexicographical_compare(InIt1 F1, InIt1 L1,
		InIt2 F2, InIt2 L2, Pr P) {
			for (; F1 != L1 && F2 != L2; ++F1, ++F2)
				if (P(*F1, *F2))
					return (true);
				else if (P(*F2,*F1))
					return (false);
			return (F1 == L1 && F2 != L2);
		}

	template<class T> inline
		const T& max(const T& X, const T& Y) {
			return (X < Y ? Y : X);
		}

	template<class T, class Pr> inline
		const T& max(const T& X, const T& Y, Pr P) {
			return (P(X,Y) ? Y : X);
		}

	template<class T> inline
		const T& min(const T& X, const T& Y) {
			return (Y < X ? Y : X);
		}

	template<class T, class Pr> inline
		const T& min(const T& X, const T& Y, Pr P) {
			return (P(Y,X) ? Y : X);
		}

	template <class T> inline
	void swap(T& X, T& Y) {
		T Tmp = X;
		X = Y, Y = Tmp;
	}
}
#endif