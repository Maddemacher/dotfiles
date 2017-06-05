(setq vue-packages
  '(
    (vue-mode :location (recipe :fetcher github :repo "codefalling/vue-mode"))
	))


(defun vue/init-vue-mode ()
    (use-package vue-mode))
