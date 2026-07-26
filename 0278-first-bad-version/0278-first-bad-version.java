public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        int l = 1;
        int r = n;

        while (l <= r) {
            int m = l + (r - l) / 2;

            if (isBadVersion(m)) {
                // m is bad, but an earlier bad version may exist.
                r = m - 1;
            } else {
                // m is good, so the first bad version is after m.
                l = m + 1;
            }
        }

        return l;
    }
}