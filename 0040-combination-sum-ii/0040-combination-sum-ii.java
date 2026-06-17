class Solution {
    List<List<Integer>> result = new ArrayList<>();

    void solve(int[] candidates, int target, int i, List<Integer> combination, int sum) {
        if (sum == target) {
            result.add(new ArrayList<>(combination));
            return;
        }

        if (sum > target || i >= candidates.length) {
            return;
        }

        combination.add(candidates[i]);
        solve(candidates, target, i + 1, combination, sum + candidates[i]);

        for (; i + 1 < candidates.length && candidates[i] == candidates[i + 1]; i++);

        combination.remove(combination.size() - 1);
        solve(candidates, target, i + 1, combination, sum);
    }

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        solve(candidates, target, 0, new ArrayList<>(), 0);
        return result;
    }
}