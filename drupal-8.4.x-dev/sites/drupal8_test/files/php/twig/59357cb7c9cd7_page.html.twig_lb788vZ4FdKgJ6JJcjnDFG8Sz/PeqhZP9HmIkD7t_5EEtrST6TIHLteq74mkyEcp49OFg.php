<?php

/* themes/zurb_foundation/templates/page.html.twig */
class __TwigTemplate_d213655768cbc56707e529e6e421afc5077acaa1fead3159c014955eb0c242fb extends Twig_Template
{
    public function __construct(Twig_Environment $env)
    {
        parent::__construct($env);

        $this->parent = false;

        $this->blocks = array(
        );
    }

    protected function doDisplay(array $context, array $blocks = array())
    {
        $tags = array("if" => 69, "spaceless" => 160);
        $filters = array("t" => 81, "date" => 203);
        $functions = array("path" => 111);

        try {
            $this->env->getExtension('Twig_Extension_Sandbox')->checkSecurity(
                array('if', 'spaceless'),
                array('t', 'date'),
                array('path')
            );
        } catch (Twig_Sandbox_SecurityError $e) {
            $e->setSourceContext($this->getSourceContext());

            if ($e instanceof Twig_Sandbox_SecurityNotAllowedTagError && isset($tags[$e->getTagName()])) {
                $e->setTemplateLine($tags[$e->getTagName()]);
            } elseif ($e instanceof Twig_Sandbox_SecurityNotAllowedFilterError && isset($filters[$e->getFilterName()])) {
                $e->setTemplateLine($filters[$e->getFilterName()]);
            } elseif ($e instanceof Twig_Sandbox_SecurityNotAllowedFunctionError && isset($functions[$e->getFunctionName()])) {
                $e->setTemplateLine($functions[$e->getFunctionName()]);
            }

            throw $e;
        }

        // line 57
        echo "
<div class=\"off-canvas-wrapper\">
  <div class=\"inner-wrap off-canvas-wrapper-inner\" id=\"inner-wrap\" data-off-canvas-wrapper>
    <aside id=\"left-off-canvas-menu\" class=\"off-canvas left-off-canvas-menu position-left\" role=\"complementary\" data-off-canvas>
      ";
        // line 61
        echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, $this->getAttribute(($context["page"] ?? null), "left_off_canvas", array()), "html", null, true));
        echo "
    </aside>

    <aside id=\"right-off-canvas-menu\" class=\"off-canvas right-off-canvas-menu position-right\" role=\"complementary\" data-off-canvas>
      ";
        // line 65
        echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, $this->getAttribute(($context["page"] ?? null), "right_off_canvas", array()), "html", null, true));
        echo "
    </aside>

    <div class=\"off-canvas-content\" data-off-canvas-content>
      ";
        // line 69
        if ($this->getAttribute(($context["page"] ?? null), "meta_header", array())) {
            // line 70
            echo "        ";
            if (($context["meta_header_grid"] ?? null)) {
                // line 71
                echo "          <div class=\"row\">
            <div class=\"large-12 columns\">
        ";
            }
            // line 74
            echo "        ";
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, $this->getAttribute(($context["page"] ?? null), "meta_header", array()), "html", null, true));
            echo "
        ";
            // line 75
            if (($context["meta_header_grid"] ?? null)) {
                // line 76
                echo "            </div>
          </div>
        ";
            }
            // line 79
            echo "      ";
        }
        // line 80
        echo "
      <header class=\"row\" role=\"banner\" aria-label=\"";
        // line 81
        echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->renderVar(t("Site header")));
        echo "\">
        ";
        // line 82
        if ((($context["linked_site_name"] ?? null) || ($context["linked_logo"] ?? null))) {
            // line 83
            echo "          <div class=\"large-2 columns\">
            ";
            // line 84
            if (($context["linked_logo"] ?? null)) {
                // line 85
                echo "              ";
                echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["linked_logo"] ?? null), "html", null, true));
                echo "
            ";
            }
            // line 87
            echo "          </div>
          <div class=\"left large-4 columns\">
            ";
            // line 89
            if (($context["is_front"] ?? null)) {
                // line 90
                echo "              <h1 id=\"site-name\">";
                echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["linked_site_name"] ?? null), "html", null, true));
                echo "</h1>
            ";
            } else {
                // line 92
                echo "              <div id=\"site-name\">";
                echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["linked_site_name"] ?? null), "html", null, true));
                echo "</div>
            ";
            }
            // line 94
            echo "          </div>
        ";
        }
        // line 96
        echo "      </header>

      ";
        // line 98
        if ($this->getAttribute(($context["page"] ?? null), "header", array())) {
            // line 99
            echo "        <div class=\"row\">
          <div class=\"large-12 columns\">
            ";
            // line 101
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, $this->getAttribute(($context["page"] ?? null), "header", array()), "html", null, true));
            echo "
          </div>
        </div>
      ";
        }
        // line 105
        echo "
      <div class=\"row\">
        ";
        // line 107
        if (($context["show_account_info"] ?? null)) {
            // line 108
            echo "          <div class=\"";
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->renderVar(((($context["site_slogan"] ?? null)) ? ("large-6") : ("large-4 columns large-offset-8"))));
            echo " columns hide-for-small\">
            <p>
              ";
            // line 110
            if (($context["logged_in"] ?? null)) {
                // line 111
                echo "                <a href=\"";
                echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->renderVar($this->env->getExtension('Drupal\Core\Template\TwigExtension')->getPath("user.page")));
                echo "\">";
                echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->renderVar(t("My Account")));
                echo "</a>
                <a href=\"";
                // line 112
                echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->renderVar($this->env->getExtension('Drupal\Core\Template\TwigExtension')->getPath("user.logout")));
                echo "\">";
                echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->renderVar(t("Logout")));
                echo "</a>
              ";
            } else {
                // line 114
                echo "                <a href=\"";
                echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->renderVar($this->env->getExtension('Drupal\Core\Template\TwigExtension')->getPath("user.login")));
                echo "\">";
                echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->renderVar(t("Login")));
                echo "</a>
                <a href=\"";
                // line 115
                echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->renderVar($this->env->getExtension('Drupal\Core\Template\TwigExtension')->getPath("user.register")));
                echo "\">";
                echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->renderVar(t("Sign Up")));
                echo "</a>
              ";
            }
            // line 117
            echo "            </p>
          </div>
        ";
        }
        // line 120
        echo "        ";
        if (($context["site_slogan"] ?? null)) {
            // line 121
            echo "          <div class=\"large-6 columns hide-for-small\">
            ";
            // line 122
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["site_slogan"] ?? null), "html", null, true));
            echo "
          </div>
        ";
        }
        // line 125
        echo "        ";
        if (($context["show_account_info"] ?? null)) {
            // line 126
            echo "          <div class=\"show-for-small\">
            <div class=\"six mobile-two columns\">
              <p>
                <a href=\"";
            // line 129
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->renderVar($this->env->getExtension('Drupal\Core\Template\TwigExtension')->getPath("user.login")));
            echo "\" class=\"radius button\">";
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->renderVar(t("Login")));
            echo "</a>
              </p>
            </div>
            <div class=\"six mobile-two columns\">
              <p>
                <a href=\"";
            // line 134
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->renderVar($this->env->getExtension('Drupal\Core\Template\TwigExtension')->getPath("user.register")));
            echo "\" class=\"radius success button\">";
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->renderVar(t("Sign Up")));
            echo "</a>
              </p>
            </div>
          </div>
        ";
        }
        // line 139
        echo "      </div>

      ";
        // line 141
        if ((($context["messages"] ?? null) &&  !($context["zurb_foundation_messages_modal"] ?? null))) {
            // line 142
            echo "      <div class=\"l-messages row\">
        <div class=\"large-12 columns\">
          ";
            // line 144
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["messages"] ?? null), "html", null, true));
            echo "
        </div>
      </div>
      ";
        }
        // line 148
        echo "
      ";
        // line 149
        if ($this->getAttribute(($context["page"] ?? null), "help", array())) {
            // line 150
            echo "      <div class=\"l-help row\">
        <div class=\"large-12 columns\">
          ";
            // line 152
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, $this->getAttribute(($context["page"] ?? null), "help", array()), "html", null, true));
            echo "
        </div>
      </div>
      ";
        }
        // line 156
        echo "
      <div class=\"row\">
        <main id=\"main\" class=\"";
        // line 158
        echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["main_grid"] ?? null), "html", null, true));
        echo " columns\" role=\"main\">
          ";
        // line 159
        if ($this->getAttribute(($context["page"] ?? null), "highlighted", array())) {
            // line 160
            echo "            ";
            ob_start();
            // line 161
            echo "              ";
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, $this->getAttribute(($context["page"] ?? null), "highlighted", array()), "html", null, true));
            echo "
            ";
            echo trim(preg_replace('/>\s+</', '><', ob_get_clean()));
            // line 163
            echo "          ";
        }
        // line 164
        echo "          <a id=\"main-content\"></a>
          ";
        // line 165
        if (($context["breadcrumb"] ?? null)) {
            echo " ";
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["breadcrumb"] ?? null), "html", null, true));
            echo " ";
        }
        // line 166
        echo "          <section>
            ";
        // line 167
        echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, $this->getAttribute(($context["page"] ?? null), "content", array()), "html", null, true));
        echo "
          </section>
        </main>
        ";
        // line 170
        if ($this->getAttribute(($context["page"] ?? null), "sidebar_first", array())) {
            // line 171
            echo "          <div id=\"sidebar-first\" class=\"";
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["sidebar_first_grid"] ?? null), "html", null, true));
            echo " columns sidebar \">
            ";
            // line 172
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, $this->getAttribute(($context["page"] ?? null), "sidebar_first", array()), "html", null, true));
            echo "
          </div>
        ";
        }
        // line 175
        echo "        ";
        if ($this->getAttribute(($context["page"] ?? null), "sidebar_second", array())) {
            // line 176
            echo "          <div id=\"sidebar-second\" class=\"";
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["sidebar_sec_grid"] ?? null), "html", null, true));
            echo " columns sidebar\">
            ";
            // line 177
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, $this->getAttribute(($context["page"] ?? null), "sidebar_second", array()), "html", null, true));
            echo "
          </div>
        ";
        }
        // line 180
        echo "      </div>
      ";
        // line 181
        if ((($this->getAttribute(($context["page"] ?? null), "footer_first", array()) || $this->getAttribute(($context["page"] ?? null), "footer_middle", array())) || $this->getAttribute(($context["page"] ?? null), "footer_last", array()))) {
            // line 182
            echo "        <footer class=\"row\">
          ";
            // line 183
            if ($this->getAttribute(($context["page"] ?? null), "footer_first", array())) {
                // line 184
                echo "            <div id=\"footer-first\" class=\"large-4 columns\">
              ";
                // line 185
                echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, $this->getAttribute(($context["page"] ?? null), "footer_first", array()), "html", null, true));
                echo "
            </div>
          ";
            }
            // line 188
            echo "          ";
            if ($this->getAttribute(($context["page"] ?? null), "footer_middle", array())) {
                // line 189
                echo "            <div id=\"footer-middle\" class=\"large-4 columns\">
              ";
                // line 190
                echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, $this->getAttribute(($context["page"] ?? null), "footer_middle", array()), "html", null, true));
                echo "
            </div>
          ";
            }
            // line 193
            echo "          ";
            if ($this->getAttribute(($context["page"] ?? null), "footer_last", array())) {
                // line 194
                echo "            <div id=\"footer-last\" class=\"large-4 columns\">
              ";
                // line 195
                echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, $this->getAttribute(($context["page"] ?? null), "footer_last", array()), "html", null, true));
                echo "
            </div>
          ";
            }
            // line 198
            echo "        </footer>
      ";
        }
        // line 200
        echo "      <div class=\"bottom-bar panel\">
        <div class=\"row\">
          <div class=\"large-12 columns\">
          &copy; ";
        // line 203
        echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, twig_date_format_filter($this->env, "now", "Y"), "html", null, true));
        echo " ";
        echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["site_name"] ?? null), "html", null, true));
        echo " ";
        echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->renderVar(t("All rights reserved.")));
        echo "
          </div>
        </div>
      </div>
    </div>
  </div>
</div>
";
    }

    public function getTemplateName()
    {
        return "themes/zurb_foundation/templates/page.html.twig";
    }

    public function isTraitable()
    {
        return false;
    }

    public function getDebugInfo()
    {
        return array (  386 => 203,  381 => 200,  377 => 198,  371 => 195,  368 => 194,  365 => 193,  359 => 190,  356 => 189,  353 => 188,  347 => 185,  344 => 184,  342 => 183,  339 => 182,  337 => 181,  334 => 180,  328 => 177,  323 => 176,  320 => 175,  314 => 172,  309 => 171,  307 => 170,  301 => 167,  298 => 166,  292 => 165,  289 => 164,  286 => 163,  280 => 161,  277 => 160,  275 => 159,  271 => 158,  267 => 156,  260 => 152,  256 => 150,  254 => 149,  251 => 148,  244 => 144,  240 => 142,  238 => 141,  234 => 139,  224 => 134,  214 => 129,  209 => 126,  206 => 125,  200 => 122,  197 => 121,  194 => 120,  189 => 117,  182 => 115,  175 => 114,  168 => 112,  161 => 111,  159 => 110,  153 => 108,  151 => 107,  147 => 105,  140 => 101,  136 => 99,  134 => 98,  130 => 96,  126 => 94,  120 => 92,  114 => 90,  112 => 89,  108 => 87,  102 => 85,  100 => 84,  97 => 83,  95 => 82,  91 => 81,  88 => 80,  85 => 79,  80 => 76,  78 => 75,  73 => 74,  68 => 71,  65 => 70,  63 => 69,  56 => 65,  49 => 61,  43 => 57,);
    }

    /** @deprecated since 1.27 (to be removed in 2.0). Use getSourceContext() instead */
    public function getSource()
    {
        @trigger_error('The '.__METHOD__.' method is deprecated since version 1.27 and will be removed in 2.0. Use getSourceContext() instead.', E_USER_DEPRECATED);

        return $this->getSourceContext()->getCode();
    }

    public function getSourceContext()
    {
        return new Twig_Source("", "themes/zurb_foundation/templates/page.html.twig", "/var/www/html/drupal-8.4.x-dev/themes/zurb_foundation/templates/page.html.twig");
    }
}
